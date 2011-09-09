#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#inlude <cmath>

#include "Point2D.h"
#include "Linesegment2D.h"

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

    T getArea (void);

    Linesegment2D<T> getTop (void);
    Linesegment2D<T> getRight (void);
    Linesegment2D<T> getBottom (void);
    Linesegment2D<T> getLeft (void);

  private:
    Point2D<T> *bottomLeft;
    Point2D<T> *topRight;
  };

  template <class T>
  Rectangle::Rectangle () {
    this->bottomLeft = new Point2D<T>;
    this->topRight = new Point2D<T>;
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
  T Rectangle::getArea () {
    T area;

    area = this->width * this->height;

    return area;
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

  Linesegment2D<T> getTop () {
    Linesegment2D<T> top = Linesegment2D();

    top.setEnd1X(this->bottomLeft->getX());
    top.setEnd1Y(this->topRight->getY());

    top.setEnd2X(this->topRight->getX());
    top.setEnd2Y(this->topRight->getY());

    return top;
  }

  Linesegment2D<T> getRight () {
    Linesegment2D<T> right = Linesegment2D();

    right.setEnd1X(this->topRight->getX());
    right.setEnd1Y(this->topRight->getY());

    right.setEnd2X(this->topRight->getX());
    right.setEnd2Y(this->bottomLeft->getY());

    return right;
  }

  Linesegment2D<T> getBottom () {
    Linesegment2D<T> bottom = Linesegment2D();

    bottom.setEnd1X(this->topRight->getX());
    bottom.setEnd1Y(this->bottomLeft->getY());

    bottom.setEnd2X(this->bottomLeft->getX());
    bottom.setEnd2Y(this->bottomLeft->getY());

    return bottom;
  }

  Linesegment2D<T> getLeft () {
    Linesegment2D<T> left = Linesegment2D();

    left.setEnd1X(this->bottomLeft->getX());
    left.setEnd1Y(this->bottomLeft->getY());

    left.setEnd2X(this->bottomLeft->getX());
    left.setEnd2Y(this->topRight->getY());

    return left;
  }

}

#endif
