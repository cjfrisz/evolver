#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

#include <ostream>

namespace evolver {

  // These might be silly, but I hate magic numbers
  // They might not need to change, but it increases readability
  const int MINUTES_PER_HOUR = 60;
  const int SECONDS_PER_MINUTE = 60;
  const int MILLISECONDS_PER_SECOND = 1000;

  class TimeStamp {
  public:
    TimeStamp (void);
    ~TimeStamp (void);
    TimeStamp (const TimeStamp &original);
    
    TimeStamp &operator= (const TimeStamp &rhs);
    
    TimeStamp &operator+= (const TimeStamp &rhs);
    TimeStamp &operator-= (const TimeStamp &rhs);

    TimeStamp &operator+ (const TimeStamp &rhs);
    TimeStamp &operator- (const TimeStamp &rhs);

    int getHours (void);
    int getMinutes (void);
    int getSeconds (void);
    int getMilliseconds (void);

    void setHours (int hours);
    void setMinutes (int minutes);
    void setSeconds (int minutes);
    void setMilliseconds (int milliseconds);

    friend 
      std::ostream &operator<< (std::ostream &out, TimeStamp &time);

  protected:
    void copyTimeStamp (const TimeStamp &original);
    
  private:
    int hours;
    int minutes;
    int seconds;
    int milliseconds;

    void normalizeTime (void);
  };

}

#endif
