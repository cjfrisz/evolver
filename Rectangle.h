#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#inlude <cmath>

namespace evolver {

  template <typename T> class Point2D;
  template <typename T> class LineSegment2D;

  template <typename T>
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

    LineSegment2D<T> getTop (void);
    LineSegment2D<T> getRight (void);
    LineSegment2D<T> getBottom (void);
    LineSegment2D<T> getLeft (void);

  private:
    Point2D<T> *bottomLeft;
    Point2D<T> *topRight;
  };

  template <typename T>
  Rectangle::Rectangle () {
    this->bottomLeft = new Point2D<T>;
    this->topRight = new Point2D<T>;
  }
 
  template <typename T>
  Rectangle::~Rectangle () {
    delete bottomLeft;
    delete topRight;
  }

  template <typename T>
  Rectangle::Rectangle (const Rectangle &original) {
    *(this->bottomLeft) = *(original.bottomLeft);
    *(this->topRight) = *(original.topRight);
  }

  template <typename T>
  Rectangle &Rectangle::operator= (const Rectangle &original) {
    if (this != &original) {
      *(this->bottomLeft) = *(original.bottomLeft);
      *(this->topRight) = *(original.topRight);
    }

    return *this
  }

  template <typename T>
  T Rectangle::getWidth () {
    T width;

    width = (T)abs((this->topRight->getX()) - 
		   (this->bottomLeft->getX()));

    return width;
  }

  template <typename T>
  T Rectangle::getHeight () {
    T height;

    height = (T)abs((this->topRight->getY()) -
		    (this->bottomLeft->getY()));

    return height;
  }

  template <typename T>
  T Rectangle::getArea () {
    T area;

    area = this->width * this->height;

    return area;
  }

  template <typename T>
  void Rectangle::setWidth (T width) {
    this->topRight->setX((this->bottomLeft->getX()) + width);

    return;
  }

  template <typename T>
  void Rectangle::setHeight (T height) {
    this->topRight->setY((this->bottomLeft->getY()) + height);

    return;
  }

  LineSegment2D<T> getTop () {
    LineSegment2D<T> top = LineSegment2D<T>();

    top.setEnd1X(this->bottomLeft->getX());
    top.setEnd1Y(this->topRight->getY());

    top.setEnd2X(this->topRight->getX());
    top.setEnd2Y(this->topRight->getY());

    return top;
  }

  LineSegment2D<T> getRight () {
    LineSegment2D<T> right = LineSegment2D<T>();

    right.setEnd1X(this->topRight->getX());
    right.setEnd1Y(this->topRight->getY());

    right.setEnd2X(this->topRight->getX());
    right.setEnd2Y(this->bottomLeft->getY());

    return right;
  }

  LineSegment2D<T> getBottom () {
    LineSegment2D<T> bottom = LineSegment2D<T>();

    bottom.setEnd1X(this->topRight->getX());
    bottom.setEnd1Y(this->bottomLeft->getY());

    bottom.setEnd2X(this->bottomLeft->getX());
    bottom.setEnd2Y(this->bottomLeft->getY());

    return bottom;
  }

  LineSegment2D<T> getLeft () {
    LineSegment2D<T> left = LineSegment2D<T>();

    left.setEnd1X(this->bottomLeft->getX());
    left.setEnd1Y(this->bottomLeft->getY());

    left.setEnd2X(this->bottomLeft->getX());
    left.setEnd2Y(this->topRight->getY());

    return left;
  }

}

#endif
