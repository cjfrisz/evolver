#ifndef __JUMPBEHAVIOR_H__
#define __JUMPBEHAVIOR_H__

#include "Actor.h"

namespace evolver {

  class JumpBehavior {
  public:
    JumpBehavior (void);
    ~JumpBehavior (void);
    JumpBehavior (const JumpBehavior &original);

    JumpBehavior &operator= (const JumpBehavior &original);

    Actor *getActor (void);

    void setActor (Actor *actor);

  private:
    Actor *actor;

    void copyJumpBehavior (const JumpBehavior &original);
  };

}

#endif
