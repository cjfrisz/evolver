#include "Command.h"

namespace evolver {

  Command::Command () {
    // Nothing to do yet
  }

  Command::~Command () {
    // Nothing to do yet
  }

  Command::Command (const Command &original) {
    this->copyCommand(original);
  }

  Command &Command::operator= (const Command &rhs) {
    if (this != &rhs) {
      this->copyCommand(rhs);
    }

    return *this;
  }

  void Command::execute () {
    // Do nothing; descendants implement thsi
    
    return;
  }

  void Command::copyCommand (const Command &original) {
    // Nothing to do yet

    return;
  }

}
