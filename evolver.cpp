#include <cstdlib>
#include <iostream>
#include <string>

// Includes OpenGL and GLU libraries
#include <SFML/Window.hpp>

#include "Character.h"
#include "CharacterGL.h"
#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {
  
  // Screen constants
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;
  const int SCREEN_BPP = 32;
  const unsigned long SCREEN_STYLE = sf::Style::Close;

  // Game window title
  const std::string TITLE = "Evolver early beta 0.01";

  // Background color
  const int BACKGROUND_COLOR4I[4] = { 255, 255, 255, 255 };

  // Game-related constants
  // How far to move the character with each key press
  const int MOVE_DIST = 5;

  // Window (via SFML) for the game
  sf::Window app;

  // The character we'll be using for testing
  CharacterGL *cgl;

  // Functions used for initializing and running the game
  void quit (int code);
  void initSFML (void);
  void initGL (void);
  void initGame (void);
  
  void evolverKey (sf::Key::Code code);
  void evolverDraw (void);  
  void evolverEventLoop (void);

  void quit (int code) {
    app.Close();
    exit(code);

    return;
  }

  void initSFML () {
    sf::WindowSettings settings;

    
    
    app.Create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP),
	       TITLE,
	       SCREEN_STYLE,
	       settings);

    return;
  }

  void initGL (void) {
    glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return;
  }

  void initGame (void) {
    Coordinates<float> *origin = new Coordinates<float>();
    Character *character = new Character();
    Hitbox *charBox = new Hitbox();

    origin->setX(0);
    origin->setY(0);
    
    cgl = new CharacterGL();

    character->setOrigin(origin);

    charBox->setHeight(CHARACTER_SIZE);
    charBox->setWidth(CHARACTER_SIZE);
    character->setBox(charBox);

    cgl->setCharacter(character);

    return;
  }

  void evolverKey (sf::Key::Code code) {
    switch (code) 
      {
      case sf::Key::Up:
	cgl->getCharacter()->moveUp(MOVE_DIST);
	break;
      case sf::Key::Down:
	cgl->getCharacter()->moveDown(MOVE_DIST);
	break;
      case sf::Key::Left:
	cgl->getCharacter()->moveLeft(MOVE_DIST);
	break;
      case sf::Key::Right:
	cgl->getCharacter()->moveRight(MOVE_DIST);
	break;
      case sf::Key::Escape:
      case sf::Key::Q:
	quit(EXIT_SUCCESS);
	break;
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

    cgl->draw(true);
    
    app.Display();
    
    return;
  }

  void evolverEventLoop (void) {
    bool done;
    sf::Event event;

    done = false;

    while (app.IsOpened()) {
      
      while ((done == false) && (app.GetEvent(event))) {
	evolverDraw();
	
	switch (event.Type) 
	  {
	  case sf::Event::KeyPressed:
	    evolverKey(event.Key.Code);
	    break;
	  case sf::Event::Closed:
	    done = true;
	    break;
	  }
      }
      
    }

    return;
  }
}

int main (int argc, char *argv[]) {
  evolver::initSFML();
  evolver::initGL();
  evolver::initGame();
  
  evolver::evolverEventLoop();
  
  evolver::quit(EXIT_SUCCESS);
  
  return EXIT_SUCCESS;
}
