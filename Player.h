#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor.h"
#include "Controller.h"

namespace evolver {

  class Player {
  public:
    Player (void);
    virtual ~Player (void);
    Player (const Player &original);

    Player &operator= (const Player &rhs);

    Actor *getActor (void);
    Controller *getController (void);

    void setActor (Actor *actor);
    void setController (Controller *controller);

  protected:
    void copyPlayer (const Player &original);

  private:
    Actor *actor;
    Controller *controller;
  };

}

#endif
