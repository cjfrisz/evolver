#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <string>

namespace evolver {

  const std::string SEPARATOR = " = ";

  const bool FULLSCREEN_DEFAULT = false;
  const int SCREEN_WIDTH_DEFAULT = 640;
  const int SCREEN_HEIGHT_DEFAULT = 480;
  const int COLOR_DEPTH_DEFAULT = 32;
  
  const int KEY_UP_DEFAULT = 'w';
  const int KEY_DOWN_DEFAULT = 's';
  const int KEY_LEFT_DEFAULT = 'a';
  const int KEY_RIGHT_DEFAULT = 'd';
  
  class Config {
  public:
    Config (void);
    ~Config (void);
    Config (const Config &original);

    bool getFullscreen (void);
    int getScreenWidth (void);
    int getScreenHeight (void);
    int getColorDepth (void);

    int getKeyUp (void);
    int getKeyDown (void);
    int getKeyLeft (void);
    int getKeyRight (void);
    int getKeyQuit (void);

    void setFullscreen (bool fullscreen);
    void setScreenWidth (int screenWidth);
    void setScreenHeight (int screenHeight);
    void setColorDepth (int colorDepth);
    
    void setKeyUp (int keyUp);
    void setKeyDown (int keyDown);
    void setKeyLeft (int keyLeft);
    void setKeyRight (int keyRight);
    void setKeyQuit (int keyQuit);

    bool loadConfig (const char *configPath);
    bool writeConfig (const char *configPath);
    
  private:
    bool fullscreen;
    int screenWidth;
    int screenHeight;
    int colorDepth;
    int keyUp;
    int keyDown;
    int keyLeft;
    int keyRight;
    int keyQuit;
  };

}

#endif
