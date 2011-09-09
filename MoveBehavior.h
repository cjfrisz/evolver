#ifndef __MOVEBEHAVIOR_H__
#define __MOVEBEHAVIOR_H__

#include "Actor.h"

namespace evolver {

  class MoveBehavior {
  public:
    MoveBehavior (void);
    ~MoveBehavior (void);
    MoveBehavior (const MoveBehavior &original);

    MoveBehavior &operator= (const MoveBehavior &original);

    Actor *getActor (void);

    void setActor (Actor *actor);

    virtual void moveUp (float elapsedTime);
    virtual void moveDown (float elapsedTime);
    virtual void moveLeft (float elapsedTime);
    virtual void moveRight (float elapsedTime);

  private:
    Actor *actor;

    void copyMoveBehavior (const MoveBehavior &original);
  };

}

#endif
