#ifndef __TEXTFALL_H__
#define __TEXTFALL_H__

#include "FallBehavior.h"

namespace evolver {

  class TextFall : public FallBehavior {
  public:
    TextFall (void);
    ~TextFall (void);
    TextFall (const TextFall &original);
    
    TextFall &operator= (const TextFall &rhs);

    void fall (void);

  protected:
    void copyTextFall (const TextFall &original);
  };

}

#endif
