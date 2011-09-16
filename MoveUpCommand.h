#ifndef __MOVEUPCOMMAND_H__
#define __MOVEUPCOMMAND_H__

#include "ActorCommand.h"

namespace evolver {

  class MoveUpCommand : public ActorCommand {
  public:
    MoveUpCommand (void);
    ~MoveUpCommand (void);
    MoveUpCommand (const MoveUpCommand &original);

    MoveUpCommand &operator= (const MoveUpCommand &rhs);

    void execute (void);
    
  protected:
    void copyMoveUpCommand (const MoveUpCommand &original);
  };

}

#endif
