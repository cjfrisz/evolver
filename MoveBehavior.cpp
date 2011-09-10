#include <cstdlib>

#include "MoveBehavior.h"

namespace evolver {
  
  MoveBehavior::MoveBehavior () {
    this->actor = NULL;
  }

  MoveBehavior::~MoveBehavior () {
    // Nothing to do yet
  }

  MoveBehavior::MoveBehavior (const MoveBehavior &original) {
    this->copyMoveBehavior(original);
  }

  MoveBehavior &MoveBehavior::operator= (const MoveBehavior &rhs) {
    if (this != &rhs) {
      this->copyMoveBehavior(rhs);
    }

    return *this;
  }

  Actor *MoveBehavior::getActor () {
    return this->actor;
  }

  void MoveBehavior::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void MoveBehavior::moveUp (float elapsedTime) { }
  
  void MoveBehavior::moveDown (float elapsedTime) { }

  void MoveBehavior::moveLeft (float elapsedTime) { }

  void MoveBehavior::moveRight (float elapsedTime) { }

  void MoveBehavior::copyMoveBehavior (const MoveBehavior &original) {
    this->actor = NULL;

    return;
  }
  
}
