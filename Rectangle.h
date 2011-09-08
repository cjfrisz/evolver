#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#inlude <cmath>

#include "Point.h"
#include "LineSegment.h"

namespace evolver {

  template <class T>
  class Rectangle {
  public:
    Rectangle (void);
    ~Rectangle (void);
    Rectangle (const Rectangle &original);
    
    Rectangle &operator= (const Rectangle &original);

    T getWidth (void);
    T getHeight (void);

    void setWidth (T width);
    void setHeight (T height);

    LineSegment<T> getTop (void);
    LineSegment<T> getRight (void);
    LineSegment<T> getBottom (void);
    LineSegment<T> getLeft (void);

  private:
    Point<T> *bottomLeft;
    Point<T> *topRight;
  };

  template <class T>
  Rectangle::Rectangle () {
    this->bottomLeft = new Point<T>;
    this->topRight = new Point<T>;
  }
 
  template <class T>
  Rectangle::~Rectangle () {
    delete bottomLeft;
    delete topRight;
  }

  template <class T>
  Rectangle::Rectangle (const Rectangle &original) {
    *(this->bottomLeft) = *(original.bottomLeft);
    *(this->topRight) = *(original.topRight);
  }

  template <class T>
  Rectangle &Rectangle::operator= (const Rectangle &original) {
    if (this != &original) {
      *(this->bottomLeft) = *(original.bottomLeft);
      *(this->topRight) = *(original.topRight);
    }

    return *this
  }

  template <class T>
  T Rectangle::getWidth () {
    T width;

    width = (T)abs((this->topRight->getX()) - 
		   (this->bottomLeft->getX()));

    return width;
  }

  template <class T>
  T Rectangle::getHeight () {
    T height;

    height = (T)abs((this->topRight->getY()) -
		    (this->bottomLeft->getY()));

    return height;
  }

  template <class T>
  void Rectangle::setWidth (T width) {
    this->topRight->setX((this->bottomLeft->getX()) + width);

    return;
  }

  template <class T>
  void Rectangle::setHeight (T height) {
    this->topRight->setY((this->bottomLeft->getY()) + height);

    return;
  }

  LineSegment<T> getTop () {
    LineSegment<T> top = LineSegment();

    top.setEnd1X(this->bottomLeft->getX());
    top.setEnd1Y(this->topRight->getY());

    top.setEnd2X(this->topRight->getX());
    top.setEnd2Y(this->topRight->getY());

    return top;
  }

  LineSegment<T> getRight () {
    LineSegment<T> right = LineSegment();

    right.setEnd1X(this->topRight->getX());
    right.setEnd1Y(this->topRight->getY());

    right.setEnd2X(this->topRight->getX());
    right.setEnd2Y(this->bottomLeft->getY());

    return right;
  }

  LineSegment<T> getBottom () {
    LineSegment<T> bottom = LineSegment();

    bottom.setEnd1X(this->topRight->getX());
    bottom.setEnd1Y(this->bottomLeft->getY());

    bottom.setEnd2X(this->bottomLeft->getX());
    bottom.setEnd2Y(this->bottomLeft->getY());

    return bottom;
  }

  LineSegment<T> getLeft () {
    LineSegment<T> left = LineSegment();

    left.setEnd1X(this->bottomLeft->getX());
    left.setEnd1Y(this->bottomLeft->getY());

    left.setEnd2X(this->bottomLeft->getX());
    left.setEnd2Y(this->topRight->getY());

    return left;
  }

}

#endif
