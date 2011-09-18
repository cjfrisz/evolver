#include "ActorCommand.h"
#include "MoveLeftCommand.h"

namespace evolver {
  
  MoveLeftCommand::MoveLeftCommand () {
    // Nothing to do yet
  }

  MoveLeftCommand::~MoveLeftCommand () {
    // Nothing to do yet
  }

  MoveLeftCommand::MoveLeftCommand (const MoveLeftCommand &original) {
    this->copyMoveLeftCommand(original);
  }

  MoveLeftCommand &MoveLeftCommand::operator= (const MoveLeftCommand &rhs) {
    if (this != &rhs) {
      this->copyMoveLeftCommand(rhs);
    }

    return *this;
  }

  void MoveLeftCommand::execute () {
    this->getActor()->getMoveBehavior()->moveLeft();
  }

  void MoveLeftCommand::copyMoveLeftCommand (const MoveLeftCommand &original) {
    this->copyActorCommand();

    return;
  }

}
