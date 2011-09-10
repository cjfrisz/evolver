#include <cstdlib>
#include <iostream>
#include <string>

// Includes OpenGL and GLU libraries
#include <SFML/Window.hpp>

#include "Controller.h"
#include "Config.h"
#include "Actor.h"
#include "ActorGL.h"
#include "Coordinates.h"

namespace evolver {
  
  // Game window title
  const std::string TITLE = "Evolver early beta 0.01";

  // Background color
  const int BACKGROUND_COLOR4I[4] = { 255, 255, 255, 255 };

  // Game-related constants
  // How far to move the actor with each key press
  const char *CONFIG_DEFAULT = "config.txt";

  // Window (via SFML) for the game
  sf::Window evolver;

  // Configuration class
  Config evolverConfig;

  // The player's controller
  Controller controller;

  // The actor we'll be using for testing
  ActorGL *agl;

  // Functions used for initializing and running the game
  void quit (int code);
  void initSFML (void);
  void initGL (void);
  void initGame (void);
  
  void evolverKey (sf::Key::Code code, float timeElapsed);
  void evolverDraw (void);  
  void evolverEventLoop (void);

  void quit (int code) {
    evolver.Close();
    exit(code);

    return;
  }

  void initSFML () {
    sf::WindowSettings settings;

    evolver.Create(sf::VideoMode(evolverConfig.getScreenWidth(),
			     evolverConfig.getScreenHeight(),
			     evolverConfig.getColorDepth()),
	       TITLE,
	       (evolverConfig.getFullscreen() ?
		(sf::Style::Fullscreen) :
		(sf::Style::Resize | sf::Style::Close)),
	       settings);

    return;
  }

  void initGL (void) {
    glViewport(0, 
	       0, 
	       (GLsizei)evolverConfig.getScreenWidth(), 
	       (GLsizei)evolverConfig.getScreenHeight());

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, 
	       evolverConfig.getScreenWidth(), 
	       0, 
	       evolverConfig.getScreenHeight());

    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return;
  }

  void initGame (void) {
    Actor *actor = new Actor();
    
    actor->setActorOriginX(0);
    actor->setActorOriginY(0);
    
    agl = new ActorGL();

    controller.setControlled(actor);
    agl->setActor(actor);

    return;
  }

  void evolverKey (sf::Key::Code code, float timeElapsed) {
    if (code == evolverConfig.getKeyQuit()) {
      quit(EXIT_SUCCESS);
    }
    else {
      controller.handleControl(controller.controlToAction(code),
			       timeElapsed);
    }

    return;
  }

  void evolverDraw (void) {
    glClearColor(BACKGROUND_COLOR4I[0],
		 BACKGROUND_COLOR4I[1],
		 BACKGROUND_COLOR4I[2],
		 BACKGROUND_COLOR4I[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    agl->draw(true);
    
    evolver.Display();
    
    return;
  }

  void evolverEventLoop (void) {
    bool done;
    float elapsedTime;
    sf::Event event;
    sf::Clock clock;

    done = false;

    while (evolver.IsOpened()) {
      
      elapsedTime = clock.GetElapsedTime();
      clock.Reset();
      
      while ((done == false) && (evolver.GetEvent(event))) {
	
	switch (event.Type) 
	  {
	  case sf::Event::KeyPressed:
	    evolverKey(event.Key.Code, elapsedTime);
	    break;
	  case sf::Event::Closed:
	    done = true;
	    break;
	  }
      
      }

      evolverDraw();
      
    }

    return;
  }
}

int main (int argc, char *argv[]) {
  bool configSuccess;

  configSuccess = 
    evolver::evolverConfig.loadConfig(evolver::CONFIG_DEFAULT);
  if (configSuccess == false) {
    std::cerr << 
      "Failed to load standard configuration file " <<
      "\'" << evolver::CONFIG_DEFAULT << "\'" <<
      std::endl;
    std::cerr << "Generating new configuration file " <<
      "and using default settings." <<
      std::endl;

    // Create a new configuration file
    evolver::evolverConfig.writeConfig(evolver::CONFIG_DEFAULT);

    // However, we're just going to use the defaults defined in
    // Config.h
  }

  evolver::controller.
    setControlActionPair(evolver::evolverConfig.getKeyUp(),
			 evolver::UP);
  evolver::controller.
    setControlActionPair(evolver::evolverConfig.getKeyDown(),
			 evolver::DOWN);
  evolver::controller.
    setControlActionPair(evolver::evolverConfig.getKeyLeft(),
			 evolver::LEFT);
  evolver::controller.
    setControlActionPair(evolver::evolverConfig.getKeyRight(),
			 evolver::RIGHT);

  evolver::initSFML();
  evolver::initGL();
  evolver::initGame();
  
  evolver::evolverEventLoop();
  
  evolver::quit(EXIT_SUCCESS);
  
  return EXIT_SUCCESS;
}
