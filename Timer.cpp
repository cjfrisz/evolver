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

  TimeStamp *Timer::getMark () {
    return this->mark;
  }

  void Timer::setMark (TimeStamp *mark) {
    this->mark = mark;

    return;
  }

  int Timer::elapsedHours () {
    int hours;

    hours = this->mark->getHours();

    delete this->mark;
    this->mark = Clock.getClock()->getTime();

    return hours;
  }

  int Timer::elapsedMinutes () {
    int minutes;

    minutes = this->mark->getMinutes();

    delete this->mark;
    this->mark = Clock.getClock()->getTime();

    return minutes;
  }

  int Timer::elapsedSeconds () {
    int seconds;

    seconds = this->mark->getSeconds();

    delete this->mark;
    this->mark = Clock.getClock()->getTime();

    return seconds;
  }

  int Timer::elapsedMilliseconds () {
    int milliseconds;

    milliseconds = this->mark->getMilliseconds();

    delete this->mark;
    this->mark = Clock.getClock()->getTime();

    return milliseconds;
  }

  TimeStamp *Timer::elapsedTime () {
    TimeStamp *elapsedTime;

    *elapsedTime = *(Clock.getClock()->getTime()) - *(this->mark);
    delete this->mark;
    this->mark = Clock.getClock()->getTime();

    return elapsedTime;
  }
  
  void Timer::copyTimer (const Timer &original) {
    *(this->mark) = *(original.mark);

    return;
  }

}

