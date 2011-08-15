#include "Coordinates.h"

namespace cjfrisz {

  Coordinates::Coordinates () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }

  Coordinates::~Coordinates () {
    // Nothing to do yet
  }

  Coordinates::Coordinates (const Coordinates &original) {
    // Nothing to do yet
  }

  int Coordinates::getX (void) {
    return this->x;
  }

  int Coordinates::getY (void) {
    return this->y;
  }

  int Coordinates::getZ (void) {
    return this->z;
  }

  void Coordinates::setX (int x) {
    this->x = x;

    return;
  }

  void Coordinates::setY (int y) {
    this->y = y;

    return;
  }

  void Coordinates::setZ (int z) {
    this->z = z;

    return;
  }

}
