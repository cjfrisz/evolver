#ifndef __CHARACTERGL_H__
#define __CHARACTERGL_H__

#include "Character.h"

namespace evolver {

  const int CHARACTER_SIZE = 30;

  const float CHARACTER_COLOR3F[3] = { 0.5, 0.25, 0.25 };
  const float DEBUG_HITBOX_COLOR3F[3] = { 0.25, 1.0, 0.25 };

  class CharacterGL {
  public:
    CharacterGL (void);
    ~CharacterGL (void);
    CharacterGL (const CharacterGL &original);
    CharacterGL &operator= (const CharacterGL &original);

    Character *getCharacter (void);
    
    void setCharacter (Character *character);

    void draw (bool debug=false);

  private:
    Character *character;
  };

}

#endif
