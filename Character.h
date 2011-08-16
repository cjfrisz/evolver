#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {

  class Character {
  public:
    Character (void);
    ~Character (void);
    Character (const Character &original);
    Character &operator= (const Character &original);

    Coordinates *getOrigin (void);
    Hitbox *getBox (void);

    void setOrigin (Coordinates *origin);
    void setBox (Hitbox *box);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveRight (int dist);
    void moveLeft (int dist);

  private:
    Coordinates *origin;
    Hitbox *box;
  };

}

#endif
