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
  Rectangle::Rectangle (void) {
    this->bottomLeft = new Point<T>;
    this->topRight = new Point<T>;
  }
 
  template <class T>
  Rectangle::~Rectangle (void) {
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
  T Rectangle::getWidth (void) {
    T width;

    width = (T)abs((this->topRight->getX()) - 
		   (this->bottomLeft->getX()));

    return width;
  }

  template <class T>
  T Rectangle::getHeight (void) {
    T height;

    height = (T)abs((this->topRight->getY()) -
		    (this->bottomLeft->getY()));

    return height;
  }

  void Rectangle::setWidth (

}

#endif
