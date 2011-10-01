#ifndef __ACTORCOMMAND_H__
#define __ACTORCOMMAND_H__

#include "Command.h"

namespace evolver {

  class Actor;

  class ActorCommand : public Command {
  public:
    ActorCommand (void);
    virtual ~ActorCommand (void);
    ActorCommand (const ActorCommand &original);

    ActorCommand &operator= (const ActorCommand &rhs);

    Actor &getActor (void);

    void setActor (Actor &actor);

    virtual void execute (void) = 0;
    
  protected:
    void copyActorCommand (const ActorCommand &original);
    
  private:
    Actor actor;
  };

}

#endif
