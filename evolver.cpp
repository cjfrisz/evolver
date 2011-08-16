#include <cstdlib>
#include <iostream>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Character.h"
#include "CharacterGL.h"
#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {
  
  const int SCREEN_WIDTH = 400;
  const int SCREEN_HEIGHT = 600;

  const int BACKGROUND_COLOR4I[4] = { 255, 255, 255, 0 };

  const int MOVE_DIST = 5;

  SDL_Surface *screen = NULL;

  CharacterGL *cgl;
  Character *character;
  Hitbox *charBox;

  void quit (int code);
  void initSDL (void);
  void initGL (void);
  void initGame (void);
  
  void evolverKey (SDL_keysym *keysym);
  void evolverDraw (void);  
  void evolverEventLoop (void);

  void quit (int code) {
    SDL_Quit();
    exit(code);

    return;
  }

  void initSDL (void) {
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
    int bpp = 32;//SDL_GetVideoInfo()->vfmt->BitsPerPixel;
    int flags = SDL_OPENGL | SDL_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      std::cerr << "Error initializing SDL." << std::endl;
      quit(EXIT_FAILURE);
    }

    if (SDL_SetVideoMode(width, height, bpp, flags) == 0) {
      std::cerr << "Error initializing video." << std::endl;
      quit(EXIT_FAILURE);
    }
    
  }

  void initGL (void) {
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);

    return;
  }

  void initGame (void) {
    Coordinates *origin = new Coordinates();

    origin->setX(0);
    origin->setY(0);
    
    cgl = new CharacterGL();
    character = new Character();
    charBox = new Hitbox();

    character->setOrigin(origin);

    charBox->setHeight(CHARACTER_SIZE);
    charBox->setWidth(CHARACTER_SIZE);
    character->setBox(charBox);

    cgl->setCharacter(character);

    return;
  }

  void evolverKey (SDL_keysym *keysym) {
    switch (keysym->sym) 
      {
      case SDLK_UP:
	cgl->getCharacter()->moveUp(MOVE_DIST);
	break;
      case SDLK_DOWN:
	cgl->getCharacter()->moveDown(MOVE_DIST);
	break;
      case SDLK_LEFT:
	cgl->getCharacter()->moveLeft(MOVE_DIST);
	break;
      case SDLK_RIGHT:
	cgl->getCharacter()->moveRight(MOVE_DIST);
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

    glTranslatef((float)cgl->getCharacter()->getOrigin()->getX(),
		 (float)cgl->getCharacter()->getOrigin()->getY(),
		 0.0);
    cgl->draw();
    glTranslatef((float)-(cgl->getCharacter()->getOrigin()->getX()),
		 (float)-(cgl->getCharacter()->getOrigin()->getY()),
		 0.0);

    SDL_GL_SwapBuffers();

    return;
  }

  void evolverEventLoop (void) {
    bool done;
    SDL_Event event;

    done = false;

    while ((done == false) && (SDL_WaitEvent(&event))) {
      switch (event.type) 
	{
	case SDL_KEYDOWN:
	  evolverKey(&event.key.keysym);
	  break;
	case SDL_QUIT:
	  done = true;
	  break;
	}

      evolverDraw();
    }

    return;
  }

}

int main (int argc, char *argv[]) {
  evolver::initSDL();
  evolver::initGL();
  evolver::initGame();
  
  evolver::evolverEventLoop();
  
  evolver::quit(EXIT_SUCCESS);
  
  return EXIT_SUCCESS;
}
