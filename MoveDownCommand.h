#ifndef __MOVEDOWNCOMMAND_H__
#define __MOVEDOWNCOMMAND_H__

#include "ActorCommand.h"

namespace evolver {

  class MoveDownCommand : public ActorCommand {
  public:
    MoveDownCommand (void);
    ~MoveDownCommand (void);
    MoveDownCommand (const MoveDownCommand &original);

    MoveDownCommand &operator= (const MoveDownCommand &rhs);

    void execute (void);
    
  protected:
    void copyMoveDownCommand (const MoveDownCommand &original);
  };

}

#endif
