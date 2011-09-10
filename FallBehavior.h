#ifndef __FALLBEHAVIOR_H__
#define __FALLBEHAVIOR_H__

namespace evolver { 

  class Actor;

  class FallBehavior {
  public:
    FallBehavior (void);
    virtual ~FallBehavior (void);
    FallBehavior (const FallBehavior &original);

    FallBehavior &operator= (const FallBehavior &rhs);

    Actor *getActor (void);

    void setActor (Actor *actor);

    virtual void fall (float timeElapsed);

  protected:
    void copyFallBehavior (const FallBehavior &original);

  private:
    Actor *actor;
  };

}

#endif
