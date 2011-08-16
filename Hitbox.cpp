#include "Coordinates.h"
#include "Hitbox.h"

namespace evolver {

  Hitbox::Hitbox (void) {
    this->lowerLeft = new Coordinates();
    this->upperRight = new Coordinates();
  }

  Hitbox::~Hitbox (void) {
    // Nothing to do yet
  }

  Hitbox::Hitbox (const Hitbox &original) {
    // Nothing to do yet
  }

  void Hitbox::setHeight (int height) {
    this->upperRight->setY((this->lowerLeft->getY() + height));

    return;
  }

  void Hitbox::setWidth (int width) {
    this->upperRight->setX((this->lowerLeft->getX() + width));

    return;
  }

  Coordinates Hitbox::getLowerLeft () {
    Coordinates lowerLeft = Coordinates();

    lowerLeft.setX(this->lowerLeft->getX());
    lowerLeft.setY(this->lowerLeft->getY());

    return lowerLeft;
  }

  Coordinates Hitbox::getLowerRight () {
    Coordinates lowerRight = Coordinates();

    lowerRight.setX(this->upperRight->getX());
    lowerRight.setY(this->lowerLeft->getY());

    return lowerRight;
  }

  Coordinates Hitbox::getUpperRight () {
    Coordinates upperRight = Coordinates();
    
    upperRight.setX(this->upperRight->getX());
    upperRight.setY(this->upperRight->getY());
    
    return upperRight;
  }

  Coordinates Hitbox::getUpperLeft () {
    Coordinates upperLeft = Coordinates();

    upperLeft.setX(this->lowerLeft->getX());
    upperLeft.setY(this->upperRight->getY());

    return upperLeft;
  }

  void Hitbox::moveUp (int dist) {
    this->lowerLeft->setY(this->lowerLeft->getY() + dist);
    this->upperRight->setY(this->upperRight->getY() + dist);

    return;
  }

  void Hitbox::moveDown (int dist) {
    this->lowerLeft->setY(this->lowerLeft->getY() - dist);
    this->upperRight->setY(this->upperRight->getY() - dist);

    return;    
  }

  void Hitbox::moveRight (int dist) {
    this->lowerLeft->setX(this->lowerLeft->getX() + dist);
    this->upperRight->setX(this->upperRight->getX() + dist);

    return;    
  }

  void Hitbox::moveLeft (int dist) {
    this->lowerLeft->setX(this->lowerLeft->getX() - dist);
    this->upperRight->setX(this->upperRight->getX() - dist);

    return;    
  }

  bool Hitbox::isPointInside (Coordinates point) {
    bool pointInside;

    if (point.getX() > this->lowerLeft->getX() &&
	point.getX() < this->upperRight->getX() &&
	point.getY() > this->lowerLeft->getY() &&
	point.getY() < this->upperRight->getY()) {
      pointInside = true;
    }
    else {
      pointInside = false;
    }

    return pointInside;
  }

}
