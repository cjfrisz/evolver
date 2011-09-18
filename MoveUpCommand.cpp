#include "ActorCommand.h"
#include "MoveUpCommand.h"

namespace evolver {
  
  MoveUpCommand::MoveUpCommand () {
    // Nothing to do yet
  }

  MoveUpCommand::~MoveUpCommand () {
    // Nothing to do yet
  }

  MoveUpCommand::MoveUpCommand (const MoveUpCommand &original) {
    this->copyMoveUpCommand(original);
  }

  MoveUpCommand &MoveUpCommand::operator= (const MoveUpCommand &rhs) {
    if (this != &rhs) {
      this->copyMoveUpCommand(rhs);
    }

    return *this;
  }

  void MoveUpCommand::execute () {
    this->getActor()->getMoveBehavior()->moveUp();
  }

  void MoveUpCommand::copyMoveUpCommand (const MoveUpCommand &original) {
    this->copyActorCommand();

    return;
  }

}
