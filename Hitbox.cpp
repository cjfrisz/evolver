#include "Coordinates.h"
#include "Hitbox.h"

namespace cjfrisz {

  Hitbox::Hitbox (void) {
    this->lowerLeft = Coordinates();
    this->upperRight = Coordinates();
  }

  Hitbox::~Hitbox (void) {
    // Nothing to do yet
  }

  Hitbox::Hitbox (const Hitbox &original) {
    // Nothing to do yet
  }

  void Hitbox::setHeight (int height) {
    this->upperRight.setY((this->lowerLeft.getY() + height));

    return;
  }

  void Hitbox::setWith (int width) {
    this->upperRight.setX((this->lowerLeft.getX() + width));

    return;
  }

  void moveUp (int dist) {
    
  }

}
