#include <string>
#include <iostream>
#include <fstream>

#include "Config.h"

namespace evolver {

  Config::Config () {
    this->fullscreen = FULLSCREEN_DEFAULT;
    this->screenWidth = SCREEN_WIDTH_DEFAULT;
    this->screenHeight = SCREEN_HEIGHT_DEFAULT;
    this->colorDepth = COLOR_DEPTH_DEFAULT;
    this->keyUp = KEY_UP_DEFAULT;
    this->keyDown = KEY_DOWN_DEFAULT;
    this->keyLeft = KEY_LEFT_DEFAULT;
    this->keyRight = KEY_RIGHT_DEFAULT;    
  }

  Config::~Config () {
    // Nothing to do yet
  }

  Config::Config (const Config &original) {
    // Nothing to do yet
  }

  bool Config::getFullscreen () {
    return this->fullscreen;
  }

  int Config::getScreenWidth () {
    return this->screenWidth;
  }

  int Config::getScreenHeight () {
    return this->screenHeight;
  }

  int Config::getColorDepth () {
    return this->colorDepth;
  }

  int Config::getKeyUp () {
    return this->keyUp;
  }

  int Config::getKeyDown () {
    return this->keyDown;
  }

  int Config::getKeyLeft () {
    return this->keyLeft;
  }

  int Config::getKeyRight () {
    return this->keyRight;
  }

  int Config::getKeyQuit () {
    return this->keyQuit;
  }

  void Config::setFullscreen (bool fullscreen) {
    this->fullscreen = fullscreen;

    return;
  }

  void Config::setScreenWidth (int screenWidth) {
    this->screenWidth = screenWidth;

    return;
  }

  void Config::setScreenHeight (int screenHeight) {
    this->screenHeight = screenHeight;

    return;
  }

  void Config::setColorDepth (int colorDepth) {
    this->colorDepth = colorDepth;

    return;
  }

  void Config::setKeyUp (int keyUp) {
    this->keyUp = keyUp;

    return;
  }

  void Config::setKeyDown (int keyDown) {
    this->keyDown = keyDown;

    return;
  }

  void Config::setKeyLeft (int keyLeft) {
    this->keyLeft = keyLeft;

    return;
  }

  void Config::setKeyRight (int keyRight) {
    this->keyRight = keyRight;

    return;
  }

  bool Config::loadConfig (const char *configPath) {
    bool success;
    std::ifstream config;
    std::string curSetting;
  
    config.open(configPath);

    if (config.is_open()) {

      while (config.good()) {

	config >> curSetting;

	if (curSetting == "fullscreen") {
	  config.ignore(SEPARATOR.length());
	  config >> this->fullscreen;
	}
	else if (curSetting == "screen_width") {
	  config.ignore(SEPARATOR.length());
	  config >> this->screenWidth;
	}
	else if (curSetting == "screen_height") {
	  config.ignore(SEPARATOR.length());
	  config >> this->screenHeight;
	}
	else if (curSetting == "color_depth") {
	  config.ignore(SEPARATOR.length());
	  config >> this->colorDepth;
	}
	else if (curSetting == "UP") {
	  config.ignore(SEPARATOR.length());
	  config >> this->keyUp;
	}
	else if (curSetting == "DOWN") {
	  config.ignore(SEPARATOR.length());
	  config >> this->keyDown;
	}
	else if (curSetting == "LEFT") {
	  config.ignore(SEPARATOR.length());
	  config >> this->keyLeft;
	}
	else if (curSetting == "RIGHT") {
	  config.ignore(SEPARATOR.length());
	  config >> this->keyRight;
	}
	else if (curSetting == "QUIT") {
	  config.ignore(SEPARATOR.length());
	  config >> this->keyQuit;
	}
	else {
	  std::cerr << "Unrecognized setting " 
		    << curSetting 
		    << std::endl;
	}
	        
      }

      config.close();

      success = true;
    }
    else {
      success = false;
    }
  
    return success;
  }

  bool Config::writeConfig (const char *configPath) {
    bool success;
    std::ofstream config;

    config.open(configPath);

    if (config.is_open()) {
      config << "fullscreen" << SEPARATOR << this->fullscreen;
      config << "screenWidth" << SEPARATOR << this->screenWidth;
      config << "screenHeight" << SEPARATOR << this->screenHeight;
      config << "colorDepth" << SEPARATOR << this->colorDepth;
      config << "keyUp" << SEPARATOR << this->keyUp;
      config << "keyDown" << SEPARATOR << this->keyDown;
      config << "keyLeft" << SEPARATOR << this->keyLeft;
      config << "keyRight" << SEPARATOR << this->keyRight;

      config.close();

      success = true;
    }
    else {
      success = false;
    }

    return success;
  }

}
