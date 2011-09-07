#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Coordinates.h"

namespace evolver {

  class Actor {
  public:
    Actor (void);
    ~Actor (void);
    Actor (const Actor &original);
    Actor &operator= (const Actor &original);

    
    

    void setOrigin (Coordinates<float> *origin);

  private:
    Coordinates<float> *origin;
  };

}

#endif
