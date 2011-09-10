#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>

namespace evolver {

  class Listener;

  class Subject {
  public:
    Subject (void);
    ~Subject (void);
    Subject (const Subject &original);

    Subject &operator= (const Subject &original);

    void attach (Listener *listener);
    void detach (Listener *listener);
    void notify (void);

  private:
    std::vector<Listener*> *attachedListeners;
  };

}

#endif
