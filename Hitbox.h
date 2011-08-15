#ifndef __HITBOX_H__
#define __HITBOX_H__

#include "Coordinates.h"

namespace evolver {
  
  class Hitbox {
  public:
    Hitbox (void);
    ~Hitbox (void);
    Hitbox (const Hitbox &original);

    void setHeight (int height);
    void setWidth (int width);

    Coordinates getLowerLeft (void);
    Coordinates getLowerRight (void);
    Coordinates getUpperRight (void);
    Coordinates getUpperLeft (void);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveRight (int dist);
    void moveLeft (int dist);

    bool isPointInside (Coordinates point);

  private:
    Coordinates *lowerLeft;
    Coordinates *upperRight;
  }

}

#endif
