#ifndef __NOMOVEMENT_H__
#define __NOMOVEMENT_H__

#include "MoveBehavior.h"

namespace evolver {

  class NoMovement : public MoveBehavior {
  public:
    NoMovement (void);
    ~NoMovement (void);
    NoMovement (const NoMovement &original);

    NoMovement &operator= (const NoMovement &original);

    void moveUp (float elapsedTime);
    void moveDown (float elapsedTime);
    void moveLeft (float elapsedTime);
    void moveRight (float elapsedTime);

  protected:
    void copyNoMovement (const NoMovement &original);
  };

}

#endif
