#include "Coordinates.h"
#include "Hitbox.h"
#include "Actor.h"

namespace evolver {

  Actor::Actor () {
    this->origin = new Coordinates<float>();
    this->box = new Hitbox();
  }

  Actor::~Actor () {
    delete this->origin;
    delete this->box;
  }

  Actor::Actor (const Actor &original) {
    *(this->origin) = *(original.origin);
    *(this->box) = *(original.box);
  }

  Actor &Actor::operator= (const Actor &original) {
    if (this != &original) {
      *(this->origin) = *(original.origin);
      *(this->box) = *(original.box);
    }

    return *this;
  }

  Coordinates<float> *Actor::getOrigin () {
    return this->origin;
  }

  Hitbox *Actor::getBox () {
    return this->box;
  }

  void Actor::setOrigin (Coordinates<float> *origin) {
    this->origin = origin;

    return;
  }

  void Actor::setBox (Hitbox *box) {
    this->box = box;

    return;
  }

  void Actor::moveUp (int dist) {
    this->origin->setY(this->origin->getY() + dist);
    this->box->moveUp(dist);
    
    return;
  }

  void Actor::moveDown (int dist) {
    this->origin->setY(this->origin->getY() - dist);
    this->box->moveDown(dist);
    
    return;
  }

  void Actor::moveRight (int dist) {
    this->origin->setX(this->origin->getX() + dist);
    this->box->moveRight(dist);
        
    return;
  }

  void Actor::moveLeft (int dist) {
    this->origin->setX(this->origin->getX() - dist);
    this->box->moveLeft(dist);
    
    return;
  }

}
