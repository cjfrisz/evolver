#ifndef __CHARACTERGL_H__
#define __CHARACTERGL_H__

#include "Character.h"

namespace evolver {

  const int CHARACTER_SIZE = 10;

  const int CHARACTER_COLOR4I[4] = { 255, 0, 0, 0 };
  const int DEBUG_HITBOX_COLOR4I[4] = { 0, 0, 0, 0 };

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
