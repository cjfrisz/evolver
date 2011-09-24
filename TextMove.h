#ifndef __TEXTMOVE_H__
#define __TEXTMOVE_H__

#include "MoveBehavior.h"
#include "Timer.h"

namespace evolver {

  class TextMove : public MoveBehavior, public Timer {
  public:
    TextMove (void);
    ~TextMove (void);
    TextMove (const TextMove &original);
    
    TextMove &operator= (const TextMove &rhs);

    void moveUp (void);   
    void moveDown (void); 
    void moveLeft (void); 
    void moveRight (void);

  protected:
    void copyTextMove (const TextMove &original);
  };

}

#endif
