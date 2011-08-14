#ifndef __HITBOX_H__
#define __HITBOX_H__

#include "Coordinates.h"

namespace cjfrisz {
  
  class Hitbox {
  public:
    Hitbox (void);
    ~Hitbox (void);
    Hitbox (const Hitbox &original);

    void setHeight (int height);
    void setWidth (int width);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveLeft (int dist);
    void moveRight (int dist);

    bool isPointInside (Coordinates point);
    bool doesLineIntersect (Coordinates point);

  private:
    Coordinates lowerLeft;
    Coordinates upperRight;
  }

}

#endif
