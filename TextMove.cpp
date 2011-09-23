#include <cstdlib>
#include <iostream>

#include "TextMove.h"
#include "MoveBehavior.h"

namespace evolver {

  TextMove::TextMove () {
    this->setActor(NULL);
  }

  TextMove::~TextMove () {
    // Nothing to do yet
  }

  TextMove::TextMove (const TextMove &original) {
    this->copyTextMove(original);
  }

  TextMove &TextMove::operator= (const TextMove &rhs) {
    if (this != &rhs) {
      this->copyTextMove(rhs);
    }

    return *this;
  }

  void TextMove::moveUp () {
    std::cout << "Moving up! (" << elapsedTime << 
      " elapsed)." << std::endl;

    return;
  }
   
  void TextMove::moveDown () {
    std::cout << "Moving down! (" << elapsedTime << 
      " elapsed)." << std::endl;

    return;
  }

  void TextMove::moveLeft () {
    std::cout << "Moving left! (" << elapsedTime << 
      " elapsed)." << std::endl;

    return;
  }

  void TextMove::moveRight () {
    std::cout << "Moving right! (" << elapsedTime << 
      " elapsed)." << std::endl;

    return;
  }

  void TextMove::copyTextMove (const TextMove &original) {
    this->copyMoveBehavior(original);

    return;
  }

}
