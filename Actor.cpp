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

  void Actor::setOrigin (Coordinates<float> *origin) {
    this->origin = origin;

    return;
  }

}
