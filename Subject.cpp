#include <vector>
#include <algorithm>

#include "Observer.h"
#include "Subject.h"

namespace evolver {
  
  Subject::Subject () {
    this->attachedObservers = new std::vector<Observer*>();
  }

  Subject::~Subject () {
    delete this->attachedObservers;
  }

  Subject::Subject (const Subject &original) {
    *(this->attachedObservers) = *(original.attachedObservers);
  }

  Subject &Subject::operator= (const Subject &rhs) {
    if (this != &rhs) {
      *(this->attachedObservers) = *(rhs.attachedObservers);
    }

    return *this;
  }

  void Subject::attach (Observer *observer) {
    std::vector<Observer*>::iterator elmnt;

    elmnt = std::find(this->attachedObservers->begin(),
		      this->attachedObservers->end(),
		      observer);

    // Only attach the observer if it's not already attached
    if (elmnt == this->attachedObservers->end()) {
      this->attachedObservers->push_back(observer);
    }
    else {
      // The observer was attached already
    }

    return;
  }

  void Subject::detach (Observer *observer) {
    std::vector<Observer*>::iterator elmnt;

    elmnt = std::find(this->attachedObservers->begin(),
		      this->attachedObservers->end(),
		      observer);

    // Only need to detach if the observer is attached
    if (elmnt != this->attachedObservers->end()) {
      this->attachedObservers->erase(elmnt);
    }
    else {
      // The observer wasn't attached
    }

    return;
  }

  void Subject::notify () {
    std::vector<Observer*>::iterator first, last;

    first = this->attachedObservers->begin();
    last = this->attachedObservers->end();
    
    for (first; first != last; first++) {
      (*first)->update();
    }
	  
    return;
  }

}
