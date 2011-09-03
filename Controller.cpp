#include <map>

#include "Controller.h"

namespace evolver {
  
  Controller::Controller () {
    this->controlled = NULL;
  }

  Controller::~Controller () {
    // Nothing to do 
  }

  Controller::Controller (const Controller &original) {
    this->controls = original.controls;
    *(this->controlled) = *(original.controlled);
  }

  Controller &Controller::operator= (const Controller &original) {
    if (this != &original) {
      this->controls = original.controls;
      *(this->controlled) = *(original.controlled);
    }
  }

  std::map<int, enum ActorAction> Controller::getControls () {
    return this->controls;
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
    this->controls.insert( std::pair<int, enum ActorAction>
			   (control, action) );

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
	this->controlled->setRunSpeed(ACTOR_MAX_SPEED);
	this->controlled->moveUp(this->controlled->getRunSpeed() * 
				 timeElapsed);
	break;
      case DOWN:
	this->controlled->setRunSpeed(ACTOR_MAX_SPEED);
	this->controlled->moveDown(this->controlled->getRunSpeed() * 
				   timeElapsed);
	break;
      case LEFT:
	this->controlled->setRunSpeed(ACTOR_MAX_SPEED);
	this->controlled->moveLeft(this->controlled->getRunSpeed() * 
				   timeElapsed);
	break;
      case RIGHT:
	this->controlled->setRunSpeed(ACTOR_MAX_SPEED);
	this->controlled->moveRight(this->controlled->getRunSpeed() * 
				    timeElapsed);
	break;
      case STOP:
	this->controlled->setRunSpeed(0);
	break;
      }
    
    return;
  }

}
