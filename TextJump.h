#ifndef __TEXTJUMP_H__
#define __TEXTJUMP_H__

#include "JumpBehavior.h"

namespace evolver {

  class TextJump : public JumpBehavior {
  public:
    TextJump (void);
    ~TextJump (void);
    TextJump (const TextJump &original);
    
    TextJump &operator= (const TextJump &rhs);

    void jump (void);

  protected:
    void copyTextJump (const TextJump &original);
  };

}

#endif
