#include <cmath>
#include <ostream>

#include "TimeStamp.h"

namespace evolver {

  TimeStamp::TimeStamp () {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
    this->milliseconds = 0;
  }

  TimeStamp::~TimeStamp () {
    // Nothing to do yet
  }

  TimeStamp::TimeStamp (const TimeStamp &original) {
    this->copyTimeStamp(original);
  }

  TimeStamp &TimeStamp::operator= (const TimeStamp &rhs) {
    if (this != &rhs) {
      this->copyTimeStamp(rhs);
    }

    return *this;
  }

  TimeStamp &TimeStamp::operator+= (const TimeStamp &rhs) {
    this->milliseconds += rhs.milliseconds;
    this->seconds += rhs.seconds;
    this->minutes += rhs.minutes;
    this->hours += rhs.hours;

    this->normalizeTime();

    return *this;
  }

  TimeStamp &TimeStamp::operator-= (const TimeStamp &rhs) {
    this->milliseconds -= rhs.milliseconds;
    this->seconds -= rhs.seconds;
    this->minutes -= rhs.minutes;
    this->hours -= rhs.hours;

    this->normalizeTime();

    return *this;
  }

  TimeStamp &TimeStamp::operator+ (const TimeStamp &rhs) {
    TimeStamp *sum;

    sum = new TimeStamp(*this);

    *sum += rhs;

    return *sum;
  }

  TimeStamp &TimeStamp::operator- (const TimeStamp &rhs) {
    TimeStamp *difference;

    difference = new TimeStamp(*this);

    *difference -= rhs;

    return *difference;
  }

  int TimeStamp::getHours () {
    return this->hours;
  }

  int TimeStamp::getMinutes () {
    return this->minutes;
  }

  int TimeStamp::getSeconds () {
    return this->seconds;
  }

  int TimeStamp::getMilliseconds () {
    return this->milliseconds;
  }

  void TimeStamp::setHours (int hours) {
    this->hours = hours;

    this->normalizeTime();

    return;
  }

  void TimeStamp::setMinutes (int minutes) {
    this->minutes = minutes;
    
    this->normalizeTime();

    return;
  }

  void TimeStamp::setSeconds (int seconds) {
    this->seconds = seconds;

    this->normalizeTime();

    return;
  }

  void TimeStamp::setMilliseconds (int milliseconds) {
    this->milliseconds = milliseconds;

    this->normalizeTime();

    return;
  }

  std::ostream &operator<< (std::ostream &out, const TimeStamp &time) {
    out << time.hours << " hours, " 
	<< time.minutes << " minutes, "
	<< time.seconds << " seconds, "
	<< time.milliseconds << " milliseconds";

    return out;
  }

  void TimeStamp::copyTimeStamp (const TimeStamp &original) {
    // Note the we're assuming values are already normalized
    this->hours = original.hours;
    this->minutes = original.minutes;
    this->seconds = original.seconds;
    this->milliseconds = original.milliseconds;

    return;
  }

  void TimeStamp::normalizeTime () {
    int negativeDifference;

    // Normalize milliseconds
    if (this->milliseconds >= MILLISECONDS_PER_SECOND) {
      this->seconds += (this->milliseconds / MILLISECONDS_PER_SECOND);
      this->milliseconds %= MILLISECONDS_PER_SECOND;
    }

    if (this->milliseconds < 0) {
      negativeDifference = 
	(int)(ceil(std::abs((double)(this->milliseconds) / 
			    (double)(MILLISECONDS_PER_SECOND))));
      this->seconds -= negativeDifference;
      this->milliseconds += 
	(negativeDifference * MILLISECONDS_PER_SECOND);
    }

    // Normalize seconds
    if (this->seconds >= SECONDS_PER_MINUTE) {
      this->minutes += (this->seconds / SECONDS_PER_MINUTE);
      this->seconds %= SECONDS_PER_MINUTE;
    }

    if (this->seconds < 0) {
      negativeDifference = 
	(int)(ceil(std::abs((double)(this->seconds) / 
			    (double)(SECONDS_PER_MINUTE))));
      this->minutes -= negativeDifference;
      this->seconds += 
	(negativeDifference * SECONDS_PER_MINUTE);
    }
    
    // Normalize minutes
    if (this->minutes >= MINUTES_PER_HOUR) {
      this->hours += (this->minutes / MINUTES_PER_HOUR);
      this->minutes %= SECONDS_PER_MINUTE;
    }

    if (this->minutes < 0) {
      negativeDifference = 
	(int)(ceil(std::abs((double)(this->minutes) / 
			    (double)(MINUTES_PER_HOUR))));
      this->hours -= negativeDifference;
      this->minutes += 
	(negativeDifference * MINUTES_PER_HOUR);
    }
  }

}
