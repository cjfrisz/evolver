#include "Clock.h"
#include "TimeStamp.h"
#include "Timer.h"

namespace evolver {

  Timer::Timer (void) {
    this->mark = new TimeStamp(*(Clock::getClock()->getTime()));
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

  TimeStamp *Timer::getMark () {
    return this->mark;
  }

  void Timer::setMark (TimeStamp *mark) {
    this->mark = mark;

    return;
  }

  TimeStamp *Timer::elapsedTime () {
    TimeStamp *currentTime;
    TimeStamp *elapsedTime;

    currentTime = Clock::getClock()->getTime();
    elapsedTime = new TimeStamp(*(currentTime) - *(this->mark));

    delete this->mark;
    this->mark = currentTime;

    return elapsedTime;
  }

  int Timer::elapsedHours () {
    return this->elapsedTime()->getHours();
  }

  int Timer::elapsedMinutes () {
    return this->elapsedTime()->getMinutes();
  }

  int Timer::elapsedSeconds () {
    return this->elapsedTime()->getSeconds();
  }

  int Timer::elapsedMilliseconds () {
    return this->elapsedTime()->getMilliseconds();
  }

  void Timer::copyTimer (const Timer &original) {
    *(this->mark) = *(original.mark);

    return;
  }

}

