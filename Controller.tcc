#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <cstdlib>
#include <map>

namespace evolver {

  class Actor;
  class MoveBehavior;
  
  enum ActorAction { UP, DOWN, LEFT, RIGHT, NOT_AN_ACTION };

  template <typename K>
  class Controller {
  public:
    Controller (void);
    ~Controller (void);
    Controller (const Controller<K> &original);

    Controller<K> &operator= (const Controller<K> &original);

    std::map<K, enum ActorAction> *getControls (void);
    Actor *getControlled (void);
    enum ActorAction controlToAction (K control);

    void setControlActionPair (K control, enum ActorAction action);
    void setControlled (Actor *controlled);

    void handleControl (enum ActorAction);

  protected:
    void copyController (const Controller<K> &original);

  private:
    std::map<K, enum ActorAction> *controls;
    Actor *controlled;
  };

  template <typename K>
  Controller<K>::Controller () {
    this->controls = new std::map<K, enum ActorAction>();
    this->controlled = NULL;
  }

  template <typename K>
  Controller<K>::~Controller () {
    delete this->controls;
  }

  template <typename K>
  Controller<K>::Controller (const Controller<K> &original) {
    this->copyController(original);
  }

  template <typename K>
  Controller<K> &Controller<K>::operator= 
    (const Controller<K> &original) {
    if (this != &original) {
      this->copyController(original);
    }

    return *this;
  }

  template <typename K>
  std::map<K, enum ActorAction> *Controller<K>::getControls () {
    return this->controls;
  }

  template <typename K>
  Actor *Controller<K>::getControlled () {
    return this->controlled;
  }

  template <typename K>
  enum ActorAction Controller<K>::controlToAction (K control) {
    enum ActorAction action;

    if (this->controls->find(control) != this->controls->end()) {
      action = this->controls->find(control)->second;
    }
    else {
      action = NOT_AN_ACTION;
    }

    return action;
  }

  template <typename K>
  void Controller<K>::setControlActionPair (K control, 
					 enum ActorAction action) {
    this->controls->insert(this->controls->begin(), 
			   std::pair<K, enum ActorAction>(control, 
							    action));

    return;
  }

  template <typename K>
  void Controller<K>::setControlled (Actor *controlled) {
    this->controlled = controlled;

    return;
  }

  template <typename K>
  void Controller<K>::handleControl (enum ActorAction action) {
    switch (action) 
      {
      case UP:
	this->controlled->getMoveBehavior()->moveUp();
	break;
      case DOWN:
	this->controlled->getMoveBehavior()->moveDown();
	break;
      case LEFT:
	this->controlled->getMoveBehavior()->moveLeft();
	break;
      case RIGHT:
	this->controlled->getMoveBehavior()->moveRight();
	break;
      }
    
    return;
  }

  template <typename K>
  void Controller<K>::copyController (const Controller<K> &original) {
    *(this->controls) = *(original.controls);
    this->controlled = original.controlled;

    return;
  }

}

#endif
