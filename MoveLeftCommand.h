#ifndef __MOVELEFTCOMMAND_H__
#define __MOVELEFTCOMMAND_H__

#include "ActorCommand.h"

namespace evolver {

  class MoveLeftCommand : public ActorCommand {
  public:
    MoveLeftCommand (void);
    ~MoveLeftCommand (void);
    MoveLeftCommand (const MoveLeftCommand &original);

    MoveLeftCommand &operator= (const MoveLeftCommand &rhs);

    void execute (void);
    
  protected:
    void copyMoveLeftCommand (const MoveLeftCommand &original);
  };

}

#endif
