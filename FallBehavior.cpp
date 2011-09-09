#include "Actor.h"
#include "FallBehavior.h"

namespace evolver {

  FallBehavior::FallBehavior () {
    this->actor = NULL
  }

  FallBehavior::~FallBehavior () {
    // Nothing to do yet
  }

  FallBehavior::FallBehavior (const FallBehavior &original) {
    this->copyFallBehavior(original);
  }

  FallBehavior &FallBehavior::operator= (const FallBehavior &original) {
    if (this != original) {
      this->copyFallBehavior(original);
    }

    return this;
  }

  Actor *FallBehavior::getActor () {
    return this->actor;
  }

  void FallBehavior::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void FallBehavior:;copyFallBehavior (const FallBehavior &original) {
    this->actor = NULL;
  }

}
