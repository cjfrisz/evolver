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

    void moveUp (void);
    void moveDown (void);
    void moveLeft (void);
    void moveRight (void);

  protected:
    void copyNoMovement (const NoMovement &original);
  };

}

#endif
