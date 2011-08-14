#ifndef __CHARACTER_H__
#define __CHARACTER_H__

namespace cjfrisz {

  class Character {
  public:
    Character (void);
    ~Character (void);
    Character (const Character &original);

    void moveUp (void);
    void moveDown (void);
    void moveLeft (void);
    void moveRight (void);

  private:

  }

}

#endif
