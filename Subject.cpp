#include <vector>
#include <algorithm>

#include "Listener.h"

namespace evolver {
  
  Subject::Subject () {
    this->attachedListeners = new std::vector<Listner>;
  }

  Subject::~Subject () {
    delete this->attachedListeners;
  }

  Subject::Subject (const Subject &original) {
    *(this->attachedListeners) = *(original.attachedListeners);
  }

  Subject &Subject::operator= (const Subject &original) {
    if (this != original) {
      *(this->attachedListeners) = *(original.attachedListeners);
    }

    return this;
  }

  void Subject::attach (Listener *listener) {
    std::vector<Listener*>::iterator elmnt;

    elmnt = std::find(this->attachedListeners.begin(),
		      this->attachedListeners.end(),
		      listener);

    // Only attach the listener if it's not already attached
    if (*elmnt == this->attachedListeners.end()) {
      this->attachedListeners.push_back(listener);
    }
    else {
      // The listener was attached already
    }

    return;
  }

  void Subject::detach (Listener *listener) {
    std::vector<Listener*>::iterator elmnt;

    elmnt = std::find(this->attachedListeners->begin(),
		      this->attachedListeners->end(),
		      listener);

    // Only need to detach if the listener is attached
    if (*elmnt != this->attachedListeners.end()) {
      this->attachedListeners.erase(elmnt);
    }
    else {
      // The listener wasn't attached
    }

    return;
  }

  void Subject::notify () {
    std::vector<Listener*>::iterator first, last;

    first = this->attachedListeners->begin();
    last = this->attachedListeners->end();
    
    for (first; first != last; first++) {
      (*first)->update();
    }
	  
    return;
  }

}
