#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "Character.h"
#include "CharacterGL.h"

namespace evolver {

  CharacterGL::CharacterGL (void) {
    this->character = NULL;
  }

  CharacterGL::~CharacterGL (void) {
    delete this->character;
  }

  CharacterGL::CharacterGL (const CharacterGL &original) {
    *(this->character) = original->character;
  }

  CharacterGL &CharacterGL::operator= (const CharacterGL &original) {
    if (this != &original) {
      *(this->character) = original->character;
    }

    return *this;
  }

  Character *CharacterGL::getCharacter () {
    return this->character;
  }

  void CharacterGL::setCharacter (Character *character) {
    this->character = character;

    return;
  }

  void CharacterGL::draw (bool debug) {   
    glColor3fv(CHARACTER_COLOR3I);

    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(0, CHARACTER_SIZE);
    glVertex2i(CHARACTER_SIZE, CHARACTER_SIZE);
    glVertex2i(CHARACTER_SIZE, 0);    
    glEnd();

    if ((debug == true) && (this->box != NULL)) {
      // I hate mid-function declaration, but this'll save memory
      Coordinates lowerLeft = this->box->getLowerLeft();
      Coordinates lowerRight = this->box->getLowerRight();
      Coordinates upperRight = this->box->getUpperRight();
      Coordinates upperLeft = this->box->getUpperLeft();

      glColor3fv(DEBUG_HITBOX_COLOR3I);

      glBegin(GL_LINE_LOOP);
      glVertex2i(lowerLeft.getX(), lowerLeft.getY());
      glVertex2i(lowerRight.getX(), lowerRight.getY());
      glVertex2i(upperRight.getX(), upperRight.getY());
      glVertex2i(upperLeft.getX(), upperRight.getY());
      glEnd();
    }
    
    return;
  }

}
