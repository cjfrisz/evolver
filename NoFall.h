#ifndef __NOFALL_H__
#define __NOFALL_H__

#include "FallBehavior.h"

namespace evolver {

  class NoFall : public FallBehavior {
  public:
    NoFall (void);
    ~NoFall (void);
    NoFall (const NoFall &original);

    NoFall &operator= (const NoFall &rhs);

    void fall (void);
    
  protected:
    void copyNoFall (const NoFall &original);
  };

}

#endif
