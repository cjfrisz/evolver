#include <cstdlib>

#include "MoveBehavior.h"

namespace evolver {
  
  MoveBehavior::MoveBehavior (void) {
    this->actor = NULL;
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

  void MoveBehavior::copyMoveBehavior (const MoveBehavior &original) {
    this->actor = NULL;

    return;
  }
  
}
