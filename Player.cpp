#include <cstdlib>

#include "Actor.h"
#include "Controller.h"
#include "Player.h"

namespace evolver {
  
  Player::Player () {
    this->actor = NULL;
    this->controller = NULL;
  }

  Player::Player (const Player &original) {
    this->copyPlayer(original);
  }

  Player &Player::operator= (const Player &rhs) {
    if (this != &rhs) {
      this->copyPlayer(rhs);
    }

    return *this;
  }

  Actor *Player::getActor () {
    return this->actor;
  }

  Controller *Player::getController () {
    return this->controller;
  }

  void Player::setActor (Actor *actor) {
    this->actor = actor;

    return;
  }

  void Player::setController (Controller *controller) {
    this->controller = controller;

    return;
  }

  void Player::copyPlayer (const Player &original) {
    this->actor = original.actor;
    this->controller = original.controller;

    return;
  }

}
