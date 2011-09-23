#include <cstdlib>

#include "NoMovement.h"

namespace evolver {
  
  NoMovement::NoMovement () {
    this->setActor(NULL);
  }

  NoMovement::~NoMovement () {
    // Nothing to do yet
  }

  NoMovement::NoMovement (const NoMovement &original) {
    this->copyNoMovement(original);
  }

  NoMovement &NoMovement::operator= (const NoMovement &original) {
    if (this != &original) {
      this->copyNoMovement(original);
    }

    return *this;
  }

  void NoMovement::moveUp () {
    // Do nothing because we don't move

    return;
  }

  void NoMovement::moveDown () {
    // Do nothing because we don't move
    
    return;
  }

  void NoMovement::moveLeft () {
    // Do nothing because we don't move
    
    return;
  }

  void NoMovement::moveRight () {
    // Do nothing because we don't move
    
    return;
  }

  void NoMovement::copyNoMovement (const NoMovement &original) {
    // Copy stuff from the partent class first
    this->copyMoveBehavior(original);

    // Nothing else to do

    return;
  }

}
