#include <cstdlib>
#include <iostream>

#include "TextFall.h"
#include "FallBehavior.h"

namespace evolver {

  TextFall::TextFall () {
    this->setActor(NULL);
  }

  TextFall::~TextFall () {
    // Nothing to do yet
  }

  TextFall::TextFall (const TextFall &original) {
    this->copyTextFall(original);
  }

  TextFall &TextFall::operator= (const TextFall &rhs) {
    if (this != &rhs) {
      this->copyTextFall(rhs);
    }

    return *this;
  }

  void TextFall::fall () {
    std::cout << "Falling!" << std::endl;

    return;
  }

  void TextFall::copyTextFall (const TextFall &original) {
    this->copyFallBehavior(original);

    return;
  }

}
