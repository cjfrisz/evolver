#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>

namespace evolver {

  class Observer;

  class Subject {
  public:
    Subject (void);
    ~Subject (void);
    Subject (const Subject &original);

    Subject &operator= (const Subject &original);

    void attach (Observer *observer);
    void detach (Observer *observer);
    void notify (void);

  private:
    std::vector<Observer*> *attachedObservers;
  };

}

#endif
