#include "Coordinates.h"

namespace evolver {

  Coordinates<T>::Coordinates () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }

  Coordinates<T>::~Coordinates () {
    // Nothing to do yet
  }

  Coordinates<T>::Coordinates (const Coordinates &original) {
    // Nothing to do yet
  }

  T Coordinates<T>::getX (void) {
    return this->x;
  }

  T Coordinates<T>::getY (void) {
    return this->y;
  }

  T Coordinates<T>::getZ (void) {
    return this->z;
  }

  void Coordinates<T>::setX (T x) {
    this->x = x;

    return;
  }

  void Coordinates<T>::setY (T y) {
    this->y = y;

    return;
  }

  void Coordinates<T>::setZ (T z) {
    this->z = z;

    return;
  }

}
