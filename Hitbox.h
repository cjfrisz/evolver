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

    Coordinates<float> getLowerLeft (void);
    Coordinates<float> getLowerRight (void);
    Coordinates<float> getUpperRight (void);
    Coordinates<float> getUpperLeft (void);

    void moveUp (int dist);
    void moveDown (int dist);
    void moveRight (int dist);
    void moveLeft (int dist);

    bool isPointInside (Coordinates<float> point);

  private:
    Coordinates<float> *lowerLeft;
    Coordinates<float> *upperRight;
  };

}

#endif
