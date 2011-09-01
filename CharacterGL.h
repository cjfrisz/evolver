#ifndef __CHARACTERGL_H__
#define __CHARACTERGL_H__

#include "Character.h"

namespace evolver {

  const int CHARACTER_SIZE = 30;

  const int CHARACTER_COLOR3I[3] = { 128, 64, 64 };
  const int DEBUG_HITBOX_COLOR3I[3] = { 64, 255, 64 };

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
