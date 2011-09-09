#include "Coordinates.h"
#include "Hitbox.h"
#include "Actor.h"
#include "MoveBehavior.h"
#include "JumpBehavior.h"

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
    this->copyActor(original);
  }

  Actor &Actor::operator= (const Actor &original) {
    if (this != &original) {
      this->copyActor(original);
    }

    return *this;
  }

  float Actor::getActorOriginX () {
    return this->origin->getX();
  }

  float Actor::getActorOriginY () {
    return this->origin->getY();
  }

  MoveBehavior *Actor::getMoveBehavior () {
    return this->moving;
  }

  JumpBehavior *Actor::getJumpBehavior () {
    return this->jumping;
  }

  void Actor::setActorOriginX (float x) {
    this->origin->setX(x);
    
    return;
  }

  void Actor::setActorOriginY (float y) {
    this->origin->setY(y);

    return;
  }

  void Actor::setMoveBehavior (MoveBehavior *moving) {
    this->moving = moving;

    return;
  }

  void Actor::setJumpBehavior (JumpBehavior *jumping) {
    this->jumping = jumping;

    return;
  }

  void Actor::copyActor () {
    *(this->origin) = *(original.origin);
    *(this->box) = *(original.box);
    *(this->moving) = *(original.moving);
    *(this->jumping) = *(original.jumping);

    return;
  }

}
