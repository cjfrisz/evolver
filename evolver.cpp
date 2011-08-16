#include <cstdlib>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "Character.h"
#include "CharacterGL.h"
#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {
  
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;

  const int BACKGROUND_COLOR4I[4] = { 255, 255, 255, 255 };

  const int MOVE_DIST = 5;

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
    int bpp = 0;
    int flags = SDL_OPENGL;
    const SDL_VideoInfo *info;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      std::cerr << "Error initializing SDL." << std::endl;
      quit(EXIT_FAILURE);
    }

    info = SDL_GetVideoInfo();

    if (info == 0) {
      std::cerr << "Video info query failed." << std::endl;
      quit(EXIT_FAILURE);
    }

    bpp = info->vfmt->BitsPerPixel;

// SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
// SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
// SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
// SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    if (SDL_SetVideoMode(SCREEN_WIDTH, 
			 SCREEN_HEIGHT, 
			 bpp, 
			 flags) == 0) {
      std::cerr << "Error initializing video." << std::endl;
      quit(EXIT_FAILURE);
    }
    
    SDL_WM_SetCaption("Evolver early beta 0.01", NULL);

    return;
  }

  void initGL (void) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, (GLsizei)SCREEN_WIDTH, (GLsizei)SCREEN_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

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
      case SDLK_ESCAPE:
      case SDLK_q:
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

    // Draw test
    glColor4i(0, 0, 255, 255);
    
    glTranslatef((SCREEN_WIDTH / 2),
		 (SCREEN_HEIGHT / 2),
		 0.0);

    glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(100, 50);
    glVertex2i(75, 100);
    glEnd();

    glFlush();

    glTranslatef(-(SCREEN_WIDTH / 2),
		 -(SCREEN_HEIGHT / 2),
		 0.0);

    glTranslatef((float)((cgl->getCharacter()->getOrigin()->getX())),
		 (float)((cgl->getCharacter()->getOrigin()->getY())),
		 0.0);
    cgl->draw();
    glTranslatef((float)(-(cgl->getCharacter()->getOrigin()->getX())),
		 (float)(-(cgl->getCharacter()->getOrigin()->getY())),
		 0.0);

    SDL_GL_SwapBuffers();

    return;
  }

  void evolverEventLoop (void) {
    bool done;
    SDL_Event event;

    done = false;

    while ((done == false) && (SDL_WaitEvent(&event))) {
      evolverDraw();

      switch (event.type) 
	{
	case SDL_KEYDOWN:
	  evolverKey(&event.key.keysym);
	  break;
	case SDL_QUIT:
	  done = true;
	  break;
	}
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
