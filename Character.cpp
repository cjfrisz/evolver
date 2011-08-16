#include "Coordinates.h"
#include "Hitbox.h"
#include "Character.h"

namespace evolver {

  Character::Character () {
    this->origin = new Coordinates();
    this->box = new Hitbox();
  }

  Character::~Character () {
    delete this->origin;
    delete this->box;
  }

  Character::Character (const Character &original) {
    *(this->origin) = *(original.origin);
    *(this->box) = *(original.box);
  }

  Character &Character::operator= (const Character &original) {
    if (this != &original) {
      *(this->origin) = *(original.origin);
      *(this->box) = *(original.box);
    }

    return *this;
  }

  Coordinates *Character::getOrigin () {
    return this->origin;
  }

  Hitbox *Character::getBox () {
    return this->box;
  }

  void Character::moveUp (int dist) {
    this->origin->setY(this->origin->getY() + dist);
    this->box->moveUp(dist);
    
    return;
  }

  void Character::moveDown (int dist) {
    this->origin->setY(this->origin->getY() - dist);
    this->box->moveDown(dist);
    
    return;
  }

  void Character::moveRight (int dist) {
    this->origin->setX(this->origin->getX() + dist);
    this->box->moveRight(dist);
        
    return;
  }

  void Character::moveLeft (int dist) {
    this->origin->setX(this->origin->getX() - dist);
    this->box->moveLeft(dist);
    
    return;
  }

}
