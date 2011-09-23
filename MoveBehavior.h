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

    virtual void moveUp (void);
    virtual void moveDown (void);
    virtual void moveLeft (void);
    virtual void moveRight (void);

  protected:
    void copyMoveBehavior (const MoveBehavior &original);

  private:
    Actor *actor;
  };

}

#endif
