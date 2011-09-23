#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace evolver {

  // Forward declaration of TimeStamp
  class TimeStamp;

  class Clock {
  public:
    Clock *getClock (void);

    int getHours (void);
    int getMinutes (void);
    int getSeconds (void);
    int getMilliseconds (void);
    TimeStamp *getTime (void);

    void setHours (int hours);
    void setMinutes (int minutes);
    void setSeconds (int seconds);
    void setMilliseconds (int milliseconds);
    void setTime (const TimeStamp &time);

    void updateHours (int addHours);
    void updateMinutes (int addMinutes);
    void updateSeconds (int addSeconds);
    void updateMilliseconds (int addMilliseconds);
    void updateTime (const TimeStamp &time);

  private:
    TimeStamp *currentTime;

    static Clock *clock;

    Clock (void);
    ~Clock (void);
    Clock (const Clock &original);
    
    Clock &operator= (const Clock &rhs);
    
    void copyClock (const Clock &original);    
  };

  // Initialize the clock to 0
  Clock *Clock::clock = 0;

}

#endif
