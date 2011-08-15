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

  SDL_Surface *screen = NULL;

  CharacterGL *cgl;
  Character *character;
  Hitbox *charBox;

  void quit (int code);
  void initSDL (void);
  void initGL (void);
  void initGame (void);
  
  void evolverKey (SDL_keysym *keysym);
  void evolverEvent (void);
  void evolverDraw (void);  

  void quit (int code) {
    SDL_Quit();
    exit(code);

    return;
  }

  void initSDL (void) {
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
    int bpp = SDL_GetVideoInfo()->vfmt->BitsPerPixel;
    int flags = SDL_OPENGL | SDL_FULLSCREEN

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

    glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(0, width, 0, height);

    glMatrixMode(GL_MODELVIEW);

    return;
  }

  void initGame (void) {
    
  }

}
