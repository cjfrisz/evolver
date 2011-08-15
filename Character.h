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

    Coordinates *Character::getOrigin (void);
    Hitbox *Character::getBox (void);

    void Character::setOrigin (Coordinates *origin);
    void Character::setBox (Hitbox *box);

    void Character::moveUp (int dist);
    void Character::moveDown (int dist);
    void Character::moveRight (int dist);
    void Character::moveLeft (int dist);

  private:
    Coordinates *origin;
    Hitbox *box;
  }

}

#endif
