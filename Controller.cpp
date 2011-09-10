#include <cstdlib>
#include <map>

#include "Actor.h"
#include "MoveBehavior.h"
#include "Controller.h"

namespace evolver {
  
  Controller::Controller () {
    this->controls = new std::map<int, enum ActorAction>();
    this->controlled = NULL;
  }

  Controller::~Controller () {
    delete this->controls;
  }

  Controller::Controller (const Controller &original) {
    this->copyController(original);
  }

  Controller &Controller::operator= (const Controller &original) {
    if (this != &original) {
      this->copyController(original);
    }

    return *this;
  }

  std::map<int, enum ActorAction> *Controller::getControls () {
    return this->controls;
  }

  Actor *Controller::getControlled () {
    return this->controlled;
  }

  enum ActorAction Controller::controlToAction (int control) {
    enum ActorAction action;

    if (this->controls->find(control) != this->controls->end()) {
      action = this->controls->find(control)->second;
    }
    else {
      action = NOT_AN_ACTION;
    }

    return action;
  }

  void Controller::setControlActionPair (int control, 
					 enum ActorAction action) {
    this->controls->insert(this->controls->begin(), 
			   std::pair<int, enum ActorAction>(control, 
							    action));

    return;
  }

  void Controller::setControlled (Actor *controlled) {
    this->controlled = controlled;

    return;
  }

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

  void Controller::copyController (const Controller &original) {
    *(this->controls) = *(original.controls);
    this->controlled = original.controlled;

    return;
  }

}
