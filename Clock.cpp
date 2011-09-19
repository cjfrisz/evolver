#include "Clock.h"

namespace evolver {

  Clock *Clock::getClock () {
    if (this->clock == 0) {
      this->clock = new Clock();
    }

    return this->clock;
  }

  int Clock::getHours () {
    return this->hours;
  }

  int Clock::getMinutes () { 
    return this->minutes;
  }

  float Clock::getSeconds () {
    return this->seconds;
  }

  void Clock::setHours (int hours) {
    this->hours = hours;

    return;
  }

  void Clock::setMinutes (int minutes) {
    this->minutes = minutes;

    return;
  }

  void Clock::setSeconds (float seconds) {
    this->seconds = seconds;

    return;
  }

  void Clock::updateHours (int addHours) {
    this->hours += addHours;

    return;
  }

  void Clock::updateMinutes (int addMinutes) {
    this->minutes += addMinutes;

    return;
  }

  void Clock::updateSeconds (float addSeconds) {
    this->seconds += addSeconds;

    return;
  }

  Clock::Clock () {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0.0;
  }

  Clock::~Clock () {
    // Nothing to do yet
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
    this->hours = original.hours;
    this->minutes = original.minutes;
    this->seconds = original.seconds;
  }

}
