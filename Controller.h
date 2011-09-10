#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <cstdlib>
#include <map>

namespace evolver {

  class Actor;
  class MoveBehavior;
  
  enum ActorAction { UP, DOWN, LEFT, RIGHT, NOT_AN_ACTION };

  template <class Key>
  class Controller {
  public:
    Controller (void);
    ~Controller (void);
    Controller (const Controller &original);

    Controller &operator= (const Controller &original);

    std::map<Key, enum ActorAction> *getControls (void);
    Actor *getControlled (void);
    enum ActorAction controlToAction (Key control);

    void setControlActionPair (Key control, enum ActorAction action);
    void setControlled (Actor *controlled);

    void handleControl (enum ActorAction, float timeElapsed);

  protected:
    void copyController (const Controller &original);

  private:
    std::map<Key, enum ActorAction> *controls;
    Actor *controlled;
  };

  template <class Key>
  Controller::Controller () {
    this->controls = new std::map<Key, enum ActorAction>();
    this->controlled = NULL;
  }

  template <class Key>
  Controller::~Controller () {
    delete this->controls;
  }

  template <class Key>
  Controller::Controller (const Controller &original) {
    this->copyController(original);
  }

  template <class Key>
  Controller &Controller::operator= (const Controller &original) {
    if (this != &original) {
      this->copyController(original);
    }

    return *this;
  }

  template <class Key>
  std::map<Key, enum ActorAction> *Controller::getControls () {
    return this->controls;
  }

  template <class Key>
  Actor *Controller::getControlled () {
    return this->controlled;
  }

  template <class Key>
  enum ActorAction Controller::controlToAction (Key control) {
    enum ActorAction action;

    if (this->controls->find(control) != this->controls->end()) {
      action = this->controls->find(control)->second;
    }
    else {
      action = NOT_AN_ACTION;
    }

    return action;
  }

  template <class Key>
  void Controller::setControlActionPair (Key control, 
					 enum ActorAction action) {
    this->controls->insert(this->controls->begin(), 
			   std::pair<Key, enum ActorAction>(control, 
							    action));

    return;
  }

  template <class Key>
  void Controller::setControlled (Actor *controlled) {
    this->controlled = controlled;

    return;
  }

  template <class Key>
  void Controller::handleControl (enum ActorAction action, 
				  float timeElapsed) {
    switch (action) 
      {
      case UP:
	this->controlled->getMoveBehavior()->moveUp(timeElapsed);
	break;
      case DOWN:
	this->controlled->getMoveBehavior()->moveDown(timeElapsed);
	break;
      case LEFT:
	this->controlled->getMoveBehavior()->moveLeft(timeElapsed);
	break;
      case RIGHT:
	this->controlled->getMoveBehavior()->moveRight(timeElapsed);
	break;
      }
    
    return;
  }

  template <class Key>
  void Controller::copyController (const Controller &original) {
    *(this->controls) = *(original.controls);
    this->controlled = original.controlled;

    return;
  }

}

#endif
