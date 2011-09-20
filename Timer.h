#ifndef __TIMER_H__
#define __TIMER_H__

namespace evolver {

  class Timer {
  public:
    Timer (void);
    ~Timer (void);
    Timer (const Timer &original);
    
    Timer &operator= (const Timer &rhs);
    
  protected:
    void copyTimer (const Timer &original);
    
  private:
    
  };

}

#endif
