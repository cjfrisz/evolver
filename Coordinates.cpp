#include "Coordinates.h"

namespace evolver {

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

  T Coordinates::getX (void) {
    return this->x;
  }

  T Coordinates::getY (void) {
    return this->y;
  }

  T Coordinates::getZ (void) {
    return this->z;
  }

  void Coordinates::setX (T x) {
    this->x = x;

    return;
  }

  void Coordinates::setY (T y) {
    this->y = y;

    return;
  }

  void Coordinates::setZ (T z) {
    this->z = z;

    return;
  }

}
