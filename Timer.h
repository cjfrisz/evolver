#ifndef __TIMER_H__
#define __TIMER_H__

namespace evolver {

  class TimeStamp;

  class Timer {
  public:
    Timer (void);
    ~Timer (void);
    Timer (const Timer &original);
    
    Timer &operator= (const Timer &rhs);

    TimeStamp *getMark (void);

    void setMark (TimeStamp *mark);

    int elapsedHours (void);
    int elapsedMinutes (void);
    int elapsedSeconds (void);
    int elapsedMilliseconds (void);
    TimeStamp *elapsedTime (void);

  protected:
    void copyTimer (const Timer &original);
    
  private:
    TimeStamp *mark;
  };

}

#endif
