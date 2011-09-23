#include "Actor.h"
#include "MoveBehavior.h"
#include "ActorCommand.h"
#include "MoveRightCommand.h"

namespace evolver {
  
  MoveRightCommand::MoveRightCommand () {
    // Nothing to do yet
  }

  MoveRightCommand::~MoveRightCommand () {
    // Nothing to do yet
  }

  MoveRightCommand::MoveRightCommand (const MoveRightCommand &original) {
    this->copyMoveRightCommand(original);
  }

  MoveRightCommand &MoveRightCommand::operator= (const MoveRightCommand &rhs) {
    if (this != &rhs) {
      this->copyMoveRightCommand(rhs);
    }

    return *this;
  }

  void MoveRightCommand::execute () {
    this->getActor()->getMoveBehavior()->moveRight();
  }

  void
  MoveRightCommand::copyMoveRightCommand
  (const MoveRightCommand &original) {
    this->copyActorCommand(original);

    return;
  }

}
