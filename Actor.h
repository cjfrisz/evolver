#ifndef __ACTOR_H__
#define __ACTOR_H__

namespace evolver {

  template <class T> class Point2D;
  class FallBehavior;
  class JumpBehavior;
  class MoveBehavior;

  class Actor {
  public:
    Actor (void);
    ~Actor (void);
    Actor (const Actor &original);

    Actor &operator= (const Actor &original);

    float getActorOriginX (void);
    float getActorOriginY (void);
    FallBehavior &getFallBehavior (void);
    JumpBehavior &getJumpBehavior (void);
    MoveBehavior &getMoveBehavior (void);

    void setActorOriginX (float x);
    void setActorOriginY (float y);
    void setFallBehavior (FallBehavior &falling);
    void setJumpBehavior (JumpBehavior &jumping);
    void setMoveBehavior (MoveBehavior &moving);

  protected:
    void copyActor (const Actor &original);

  private:
    Point2D<float> origin;
    FallBehavior falling;
    JumpBehavior jumping;
    MoveBehavior moving;
  };

}

#endif
