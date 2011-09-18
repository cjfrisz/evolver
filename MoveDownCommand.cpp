#include "ActorCommand.h"
#include "MoveDownCommand.h"

namespace evolver {
  
  MoveDownCommand::MoveDownCommand () {
    // Nothing to do yet
  }

  MoveDownCommand::~MoveDownCommand () {
    // Nothing to do yet
  }

  MoveDownCommand::MoveDownCommand (const MoveDownCommand &original) {
    this->copyMoveDownCommand(original);
  }

  MoveDownCommand &MoveDownCommand::operator= (const MoveDownCommand &rhs) {
    if (this != &rhs) {
      this->copyMoveDownCommand(rhs);
    }

    return *this;
  }

  void MoveDownCommand::execute () {
    this->getActor()->getMoveBehavior()->moveDown();
  }

  void MoveDownCommand::copyMoveDownCommand (const MoveDownCommand &original) {
    this->copyActorCommand();

    return;
  }

}
