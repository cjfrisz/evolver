#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>

#include "Listener.h"

namespace evolver {

  class Subject {
  public:
    Subject (void);
    ~Subject (void);
    Subject (const Subject &original);

    Subject &operator= (const Subject &original);

    subscribe (Listener listener);
    unsubscribe (Listener listener);
    notify (void);

  private:
    std::vector<Listener> *registeredListeners;
  };

}

#endif
