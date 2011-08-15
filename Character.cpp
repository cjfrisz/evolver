#include "Coordinates.h"
#include "Hitbox.h"
#include "Character.h"

namespace evolver {

  Character::Character () {
    this->origin = Coordinates();
    this->box = Hitbox();
  }

  Character::~Character () {
    // Nothing to do yet
  }

  Character::Character (const Character &original) {
    // Nothing to do yet
  }

  Coordinates Character::getOrigin () {
    return this->origin;
  }

  Hitbox Character::getBox () {
    return this->box;
  }

  void Character::moveUp (int dist) {
    this->origin.setY(this->origin.getY() + dist);
    this->box.moveUp();
    
    return;
  }

  void Character::moveDown (int dist) {
    this->origin.setY(this->origin.getY() - dist);
    this->box.moveDown();
    
    return;
  }

  void Character::moveRight (int dist) {
    this->origin.setX(this->origin.getX() + dist);
    this->box.moveRight();
        
    return;
  }

  void Character::moveLeft (int dist) {
    this->origin.setX(this->origin.getX() - dist);
    this->box.moveLeft();
    
    return;
  }

}
