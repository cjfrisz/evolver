#include <cstdlib>

#include "Subject.h"
#include "Observer.h"

namespace evolver {
  
  Observer::Observer () {
    this->subject = NULL;
  }

  Observer::~Observer () {
    // Nothing to do yet
  }

  Observer::Observer (const Observer &original) {
    this->copyObserver(original);
  }

  Observer &Observer::operator= (const Observer &rhs) {
    if (this != &rhs) {
      this->copyObserver(rhs);
    }

    return *this;
  }

  Subject *Observer::getSubject () {
    return this->subject;
  }

  void Observer::setSubject (Subject *subject) {
    this->subject = subject;
  }

  void update () { 
    // Strictly virtual; do nothing here
  }

  void Observer::copyObserver (const Observer &original) {
    this->subject = original.subject;

    return;
  }

}
