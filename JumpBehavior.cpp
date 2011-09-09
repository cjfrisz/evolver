#include <cstdlib>

#include "Actor.h"
#include "JumpBehavior.h"

namespace evolver {

  JumpBehavior::JumpBehavior (void) {
    this->actor = NULL;
  }

  JumpBehavior::~JumpBehavior (void) {
    // Nothing to do yet
  }

  JumpBehavior::JumpBehavior (const JumpBehavior &original) {
    this->copyJumpBehavior(original);
  }

  JumpBehavior &JumpBehavior::operator= (const JumpBehavior &original) {
    if (this != original) {
      this->copyJumpBehavior(original);
    }

    return this;
  }

  Actor *JumpBehavior::getActor () {
    return this->actor;
  }

  void JumpBehavior::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void JumpBehavior::copyJumpBehavior (const JumpBehavior &original) {
    this->actor = NULL;

    return;
  }

}
