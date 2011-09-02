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
    *(this->character) = *(original.character);
  }

  CharacterGL &CharacterGL::operator= (const CharacterGL &original) {
    if (this != &original) {
      *(this->character) = *(original.character);
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
    glColor3fv(CHARACTER_COLOR3F);

    glBegin(GL_QUADS);
	    glVertex2i(this->character->getOrigin()->getX(), 
		       this->character->getOrigin()->getY());
	    glVertex2i(this->character->getOrigin()->getX(),
		       (this->character->getOrigin()->getY() + 
			CHARACTER_SIZE));
	    glVertex2i((this->character->getOrigin()->getX() + 
			CHARACTER_SIZE), 
		       (this->character->getOrigin()->getY() + 
			CHARACTER_SIZE));
	    glVertex2i((this->character->getOrigin()->getX() + 
			CHARACTER_SIZE), 
		       this->character->getOrigin()->getY());    
    glEnd();

    if ((debug == true) && (this->character->getBox() != NULL)) {
      // I hate mid-function declaration, but this'll save memory
      Coordinates<float> lowerLeft = 
	this->character->getBox()->getLowerLeft();
      Coordinates<float> lowerRight = 
	this->character->getBox()->getLowerRight();
      Coordinates<float> upperRight = 
	this->character->getBox()->getUpperRight();
      Coordinates<float> upperLeft = 
	this->character->getBox()->getUpperLeft();

      glColor3fv(DEBUG_HITBOX_COLOR3F);

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
