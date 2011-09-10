#include <cstdlib>
#include <map>

#include "Actor.h"
#include "MoveBehavior.h"
#include "Controller.h"

namespace evolver {
  
  Controller::Controller () {
    this->control = new std::map<int, enum ActorAction>();
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

  Actor *Controller::getControlled () {
    return this->controlled;
  }

  enum ActorAction Controller::controlToAction (int control) {
    enum ActorAction action;

    if (this->controls.find(control) != this->controls.end()) {
      action = this->controls[ control ];
    }
    else {
      action = NOT_AN_ACTION;
    }

    return action;
  }

  void Controller::setControlActionPair (int control, 
					 enum ActorAction action) {
    *(this->controls)[control] = action;

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
	this->controlled->getMoveBehavior()->moveUp(elapsedTime);
	break;
      case DOWN:
	this->controlled->getMoveBehavior()->moveDown(elapsedTime);
	break;
      case LEFT:
	this->controlled->getMoveBehavior()->moveLeft(elapsedTime);
	break;
      case RIGHT:
	this->controlled->getMoveBehavior()->moveRight(elapsedTime);
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
