#include <cstdlib>

#include "NoFall.h"

namespace evolver {

  NoFall::NoFall () {
    this->setActor(NULL);
  }

  NoFall::~NoFall () {
    // Nothing to do yet
  }

  NoFall::NoFall (const NoFall &original) {
    this->copyNoFall(original);
  }

  NoFall &NoFall::operator= (const NoFall &rhs) {
    if (this != &rhs) {
      this->copyNoFall(rhs);
    }

    return *this;
  }

  void NoFall::fall () {
    // No falling!

    return;
  }

  void NoFall::copyNoFall (const NoFall &original) {
    this->copyFallBehavior(original);

    return;
  } 

}
