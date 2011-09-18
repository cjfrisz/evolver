#include "ActorCommand.h"
#include "JumpCommand.h"

namespace evolver {
  
  JumpCommand::JumpCommand () {
    // Nothing to do yet
  }

  JumpCommand::~JumpCommand () {
    // Nothing to do yet
  }

  JumpCommand::JumpCommand (const JumpCommand &original) {
    this->copyJumpCommand(original);
  }

  JumpCommand &JumpCommand::operator= (const JumpCommand &rhs) {
    if (this != &rhs) {
      this->copyJumpCommand(rhs);
    }

    return *this;
  }

  void JumpCommand::execute () {
    this->getActor()->getMoveBehavior()->jump();
  }

  void JumpCommand::copyJumpCommand (const JumpCommand &original) {
    this->copyActorCommand();

    return;
  }

}
