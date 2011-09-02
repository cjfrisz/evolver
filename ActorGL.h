#ifndef __ACTORGL_H__
#define __ACTORGL_H__

#include "Actor.h"

namespace evolver {

  const int ACTOR_SIZE = 30;

  const float ACTOR_COLOR3F[3] = { 0.5, 0.25, 0.25 };
  const float DEBUG_HITBOX_COLOR3F[3] = { 0.25, 1.0, 0.25 };

  class ActorGL {
  public:
    ActorGL (void);
    ~ActorGL (void);
    ActorGL (const ActorGL &original);
    ActorGL &operator= (const ActorGL &original);

    Actor *getActor (void);
    
    void setActor (Actor *actor);

    void draw (bool debug=false);

  private:
    Actor *actor;
  };

}

#endif
