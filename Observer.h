#ifndef __OBSERVER_H__
#define __OBSERVER_H__

namespace evolver {
  
  class Subject;

  class Observer {
  public:
    Observer (void);
    ~Observer (void);
    Observer (const Observer &original);

    Observer &operator= (const Observer &rhs);

    Subject *getSubject (void);

    void setSubject (Subject *subject);

    virtual void update (void);

  protected:
    void copyObserver (const Observer &original);

  private:
    Subject *subject;
  };

}

#endif
