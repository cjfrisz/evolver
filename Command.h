#ifndef __COMMAND_H__
#define __COMMAND_H__

namespace evolver {

  class Command {
  public:
    Command (void);
    virtual ~Command (void);
    Command (const Command &original);
    
    Command &operator= (const Command &rhs);
    
    virtual void execute (void);

  protected:
    void copyCommand (const Command &original);
  };
  
}

#endif
