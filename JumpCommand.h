#ifndef __JUMPCOMMAND_H__
#define __JUMPCOMMAND_H__

#include "ActorCommand.h"

namespace evolver {

  class JumpCommand : public ActorCommand {
  public:
    JumpCommand (void);
    ~JumpCommand (void);
    JumpCommand (const JumpCommand &original);

    JumpCommand &operator= (const JumpCommand &rhs);

    void execute (void);
    
  protected:
    void copyJumpCommand (const JumpCommand &original);
  };

}

#endif
