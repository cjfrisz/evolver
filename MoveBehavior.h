#ifndef __MOVEBEHAVIOR_H__
#define __MOVEBEHAVIOR_H__

namespace evolver {

  class Actor;

  class MoveBehavior {
  public:
    MoveBehavior (void);
    virtual ~MoveBehavior (void);
    MoveBehavior (const MoveBehavior &original);

    MoveBehavior &operator= (const MoveBehavior &original);

    Actor *getActor (void);

    void setActor (Actor *actor);

    virtual void moveUp (float elapsedTime);
    virtual void moveDown (float elapsedTime);
    virtual void moveLeft (float elapsedTime);
    virtual void moveRight (float elapsedTime);

  protected:
    void copyMoveBehavior (const MoveBehavior &original);

  private:
    Actor *actor;
  };

}

#endif
