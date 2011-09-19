#ifndef __CLOCK_H__
#define __CLOCK_H__

namespace evolver {

  class Clock {
  public:
    Clock *getClock (void);

    int getHours (void);
    int getMinutes (void);
    float getSeconds (void);

    void setHours (int hours);
    void setMinutes (int minutes);
    void setSeconds (float seconds);

    void updateHours (int addHours);
    void updateMinutes (int addMinutes);
    void updateSeconds (float addSeconds);

  private:
    int hours;
    int minutes;
    float seconds;

    static Clock *clock = 0;

    Clock (void);
    ~Clock (void);
    Clock (const Clock &original);
    
    Clock &operator= (const Clock &rhs);
    
    void copyClock (const Clock &original);    
  };

}

#endif
