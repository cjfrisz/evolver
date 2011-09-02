#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {

  class Actor {
  public:
    Actor (void);
    ~Actor (void);
    Actor (const Actor &original);
    Actor &operator= (const Actor &original);

    Coordinates<float> *getOrigin (void);
    Hitbox *getBox (void);

    void setOrigin (Coordinates<float> *origin);
    void setBox (Hitbox *box);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveRight (int dist);
    void moveLeft (int dist);

  private:
    Coordinates<float> *origin;
    Hitbox *box;
  };

}

#endif
