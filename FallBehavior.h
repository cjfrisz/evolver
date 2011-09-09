#ifndef __FALLBEHAVIOR_H__
#define __FALLBEHAVIOR_H__

#include "Actor.h"

namespace evolver { 

  class FallBehavior {
  public:
    FallBehavior (void);
    ~FallBehavior (void);
    FallBehavior (const FallBehavior &original);

    FallBehavior &operator= (const FallBehavior &original);

    Actor *getActor (void);

    void setActor (Actor *actor);

    virtual void fall (void);

  private:
    Actor *actor;

    void copyFallBehavior (const FallBehavior &original);
  };

}

#endif
