#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {

  const int ACTOR_MOVE_SPEED = 12;

  class Actor {
  public:
    Actor (void);
    ~Actor (void);
    Actor (const Actor &original);
    Actor &operator= (const Actor &original);

    float getMoveSpeed (void);
    Coordinates<float> *getOrigin (void);
    Hitbox *getBox (void);

    void setMoveSpeed (float moveSpeed);
    void changeMoveSpeed (float speedChange);
    void setOrigin (Coordinates<float> *origin);
    void setBox (Hitbox *box);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveRight (int dist);
    void moveLeft (int dist);

  private:
    float moveSpeed;
    Coordinates<float> *origin;
    Hitbox *box;
  };

}

#endif
