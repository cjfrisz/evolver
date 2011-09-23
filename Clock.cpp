#include "TimeStamp.h"
#include "Clock.h"

namespace evolver {

  Clock *Clock::getClock () {
    if (Clock::clock == 0) {
      Clock::clock = new Clock();
    }

    return Clock::clock;
  }

  int Clock::getHours () {
    return this->currentTime->getHours();
  }

  int Clock::getMinutes () { 
    return this->currentTime->getMinutes();
  }

  int Clock::getSeconds () {
    return this->currentTime->getSeconds();
  }

  int Clock::getMilliseconds () {
    return this->currentTime->getMilliseconds();
  }

  TimeStamp *Clock::getTime () {
    TimeStamp *result;

    result = new TimeStamp();

    *result = *(this->currentTime);

    return result;
  }

  void Clock::setHours (int hours) {
    this->currentTime->setHours(hours);

    return;
  }

  void Clock::setMinutes (int minutes) {
    this->currentTime->setMinutes(minutes);

    return;
  }

  void Clock::setSeconds (int seconds) {
    this->currentTime->setSeconds(seconds);

    return;
  }

  void Clock::setMilliseconds (int milliseconds) {
    this->currentTime->setMilliseconds(milliseconds);

    return;
  }

  void Clock::setTime (const TimeStamp &time) {
    *(this->currentTime) = time;

    return;
  }

  void Clock::updateHours (int addHours) {
    int curHours;

    curHours = this->currentTime->getHours();

    this->currentTime->setHours(curHours + addHours);

    return;
  }

  void Clock::updateMinutes (int addMinutes) {
    int curMinutes;

    curMinutes = this->currentTime->getMinutes();

    this->currentTime->setMinutes(curMinutes + addMinutes);

    return;
  }

  void Clock::updateSeconds (int addSeconds) {
    int curSeconds;

    curSeconds = this->currentTime->getSeconds();

    this->currentTime->setSeconds(curSeconds + addSeconds);

    return;
  }

  void Clock::updateTime (const TimeStamp &time) {
    *(this->currentTime) += time;

    return;
  }

  Clock::Clock () {
    this->currentTime = new TimeStamp();
  }

  Clock::~Clock () {
    delete this->currentTime;
  }

  Clock::Clock (const Clock &original) {
    this->copyClock(original);
  }

  Clock &Clock::operator= (const Clock &rhs) {
    if (this != &rhs) {
      this->copyClock(rhs);
    }

    return *this;
  }

  void Clock::copyClock (const Clock &original) {
    *(this->currentTime) = *(original.currentTime);

    return;
  }

}
