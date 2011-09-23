#include "Clock.h"
#include "TimeStamp.h"
#include "Timer.h"

namespace evolver {

  Timer::Timer (void) {
    this->mark = new TimeStamp();
    this->mark->setMark(Clock.getClock()->getTime());
  }
  
  Timer::~Timer (void) {
    delete this->mark;
  }
  
  Timer::Timer (const Timer &original) {
    this->copyTimer(original);
  }
  
  Timer &Timer::operator= (const Timer &rhs) {
    if (this != &rhs) {
      this->copyTimer(rhs);
    }

    return *this;
  }
  
  void Timer::copyTimer (const Timer &original) {
    *(this->mark) = *(original.mark);

    return;
  }

}

