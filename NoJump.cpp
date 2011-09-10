#include <cstdlib>

#include "NoJump.h"

namespace evolver {

  NoJump::NoJump () {
    this->setActor(NULL);
  }

  NoJump::~NoJump () {
    // Nothing to do yet
  }

  NoJump::NoJump (const NoJump &original) {
    this->copyNoJump(original);
  }

  NoJump &NoJump::operator= (const NoJump &rhs) {
    if (this != &rhs) {
      this->copyNoJump(rhs);
    }

    return *this;
  }

  void NoJump::jump () {
    // No jumping allowed

    return;
  }

  void NoJump::copyNoJump (const NoJump &original) {
    this->copyJumpBehavior(original);

    return;
  }

}
