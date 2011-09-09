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

    bool getMoving (void);
    Actor *getActor (void);

    void setMoving (bool moving);
    void setActor (Actor *actor);

    virtual void moveUp (void);
    virtual void moveDown (void);
    virtual void moveLeft (void);
    virtual void moveRight (void);

  private:
    bool moving;
    Actor *actor;

    void copyMoveBehavior (const MoveBehavior &original);
  };

}

#endif
