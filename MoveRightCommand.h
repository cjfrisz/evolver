#ifndef __MOVERIGHTCOMMAND_H__
#define __MOVERIGHTCOMMAND_H__

#include "ActorCommand.h"

namespace evolver {

  class MoveRightCommand : public ActorCommand {
  public:
    MoveRightCommand (void);
    ~MoveRightCommand (void);
    MoveRightCommand (const MoveRightCommand &original);

    MoveRightCommand &operator= (const MoveRightCommand &rhs);

    void execute (void);
    
  protected:
    void copyMoveRightCommand (const MoveRightCommand &original);
  };

}

#endif
