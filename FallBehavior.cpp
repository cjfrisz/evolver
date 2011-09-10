#include "Actor.h"
#include "FallBehavior.h"

namespace evolver {

  FallBehavior::FallBehavior () {
    this->actor = NULL
  }

  FallBehavior::FallBehavior (const FallBehavior &original) {
    this->copyFallBehavior(original);
  }

  FallBehavior &FallBehavior::operator= (const FallBehavior &rhs) {
    if (this != rhs) {
      this->copyFallBehavior(rhs);
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

    return;
  }

}
