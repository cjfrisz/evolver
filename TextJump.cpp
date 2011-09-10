#include <cstdlib>
#include <iostream>

#include "TextJump.h"
#include "JumpBehavior.h"

namespace evolver {

  TextJump::TextJump () {
    this->setActor(NULL);
  }

  TextJump::~TextJump () {
    // Nothing to do yet
  }

  TextJump::TextJump (const TextJump &original) {
    this->copyTextJump(original);
  }

  TextJump &TextJump::operator= (const TextJump &rhs) {
    if (this != &rhs) {
      this->copyTextJump(rhs);
    }

    return *this;
  }

  void TextJump::jump () {
    std::cout << "Jumping!" << std::endl;

    return;
  }

  void TextJump::copyTextJump (const TextJump &original) {
    this->copyJumpBehavior(original);

    return;
  }

}
