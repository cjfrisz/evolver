#include <cstdlib>

#include "Point2D.tcc"
#include "Actor.h"
#include "FallBehavior.h"
#include "JumpBehavior.h"
#include "MoveBehavior.h"

namespace evolver {

  Actor::Actor () {
    this->origin = new Point2D<float>();
    this->falling = NULL;
    this->jumping = NULL;
    this->moving = NULL;
  }

  Actor::~Actor () {
    delete this->origin;

    if (this->falling != NULL) {
      delete this->falling;
    }

    if (this->jumping != NULL) {
      delete this->jumping;
    }

    if (this->moving != NULL) {
      delete this->moving;
    }
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

  FallBehavior *Actor::getFallBehavior () {
    return this->falling;
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

  void Actor::setFallBehavior (FallBehavior *falling) {
    this->falling = falling;

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

  void Actor::copyActor (const Actor &original) {
    this->origin = original.origin;
    this->falling = original.falling;
    this->jumping = original.jumping;
    this->moving = original.moving;

    return;
  }

}
