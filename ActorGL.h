#ifndef __ACTORGL_H__
#define __ACTORGL_H__

namespace evolver {

  class Actor;

  const int ACTOR_SIZE = 30;

  const float ACTOR_COLOR3F[3] = { 0.5, 0.25, 0.25 };

  class ActorGL {
  public:
    ActorGL (void);
    ~ActorGL (void);
    ActorGL (const ActorGL &original);
    ActorGL &operator= (const ActorGL &original);

    Actor *getActor (void);
    
    void setActor (Actor *actor);

    void draw (void);

  private:
    Actor *actor;
  };

}

#endif
