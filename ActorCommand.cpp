#include <cstdlib>

#include "Actor.h"
#include "ActorCommand.h"

namespace evolver {

  ActorCommand::ActorCommand () {
    this->actor = NULL;
  }

  ActorCommand::~ActorCommand () {
    // Nothing to do yet
  }

  ActorCommand::ActorCommand (const ActorCommand &original) {
    this->copyActorCommand(original);
  }

  ActorCommand &ActorCommand::operator= (const ActorCommand &rhs) {
    if (this != &rhs) {
      this->copyActorCommand(rhs);
    }

    return *this;
  }

  Actor *ActorCommand::getActor () {
    return this->actor;
  }

  void ActorCommand::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void ActorCommand::execute () {
    // Nothing to do
  
    return;
  }

  void ActorCommand::copyActorCommand (const ActorCommand &original) {
    *(this->actor) = *(original.actor);

    return;
  }

}
