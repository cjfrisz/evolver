#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Coordinates.h"

namespace evolver {

  class Actor {
  public:
    Actor (void);
    ~Actor (void);
    Actor (const Actor &original);

    Actor &operator= (const Actor &original);

    float getActorOriginX (void);
    float getActorOriginY (void);
    MoveBehavior *getMoveBehavior (void);
    JumpBehavior *getJumpBehavior (void);

    void setActorOriginX (float x);
    void setActorOriginY (float y);
    void setMoveBehavior (MoveBehavior *moving);
    void setJumpBehavior (JumpBehavior *jumping);

  private:
    Coordinates<float> *origin;
    MoveBehavior *moving;
    JumpBehavior *jumping;

    void copyActor (const Actor &original);
  };

}

#endif
