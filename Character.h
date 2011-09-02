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
