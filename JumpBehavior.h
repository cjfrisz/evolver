#ifndef __JUMPBEHAVIOR_H__
#define __JUMPBEHAVIOR_H__

namespace evolver {

  class Actor;

  class JumpBehavior {
  public:
    JumpBehavior (void);
    virtual ~JumpBehavior (void);
    JumpBehavior (const JumpBehavior &original);

    JumpBehavior &operator= (const JumpBehavior &original);

    Actor *getActor (void);

    void setActor (Actor *actor);

    virtual void jump (float TimeElapsed);

  protected:
    void copyJumpBehavior (const JumpBehavior &original);

  private:
    Actor *actor;
  };

}

#endif
