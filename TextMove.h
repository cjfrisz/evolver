#ifndef __TEXTMOVE_H__
#define __TEXTMOVE_H__

#include "MoveBehavior.h"

namespace evolver {

  class TextMove : public MoveBehavior {
  public:
    TextMove (void);
    ~TextMove (void);
    TextMove (const TextMove &original);
    
    TextMove &operator= (const TextMove &rhs);

    void moveUp (float elapsedTime);   
    void moveDown (float elapsedTime); 
    void moveLeft (float elapsedTime); 
    void moveRight (float elapsedTime);

  protected:
    void copyTextMove (const TextMove &original);
  };

}

#endif
