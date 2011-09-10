#ifndef __NOJUMP_H__
#define __NOJUMP_H__

#include "JumpBehavior.h"

namespace evolver {

  class NoJump : public JumpBehavior {
  public:
    NoJump (void);
    ~NoJump (void);
    NoJump (const NoJump &original);

    NoJump &operator= (const NoJump &original);

    void jump (void);

  protected:
    void copyNoJump (const NoJump &original);
  };

}

#endif
