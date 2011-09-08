#ifndef __LINESEGMENT_H__
#define __LINESEGMENT_H__

#include <cmath>

#include "Point.h"

namespace evolver {
  
  template <class T>
  class LineSegment {
  public:
    LineSegment (void);
    ~LineSegment (void);
    LineSegment (const LineSegment &original);
    
    LineSegment &operator= (const LineSegment &original);

    T getEnd1X (void);
    T getEnd1Y (void);
    T getEnd1Z (void);

    T getEnd2X (void);
    T getEnd2Y (void);
    T getEnd2Z (void);
    
    void setEnd1X (T x);
    void setEnd1Y (T y);
    void setEnd1Z (T z);

    void setEnd2X (T x);
    void setEnd2Y (T y);
    void setEnd2Z (T z);

    T length (void);

  private:
    Point<T> *end1;
    Point<T> *end2;
  };

  template <class T>
  LineSegment::LineSegment () {
    this->end1 = new Point<T>;
    this->end2 = new Point<T>;
  }

  template <class T>
  LineSegment::~LineSegment () {
    delete end1;
    delete end2;
  }

  template <class T>
  LineSegment::LineSegment (const LineSegment &original) {
    if (this != &original) {
      *(this->end1) = *(original.end1);
      *(this->end2) = *(original.end2);
    }

    return *this;
  }

  template <class T>
  T LineSegment::getEnd1X () {
    return this->end1->getX();
  }

  template <class T>
  T LineSegment::getEnd1Y () {
    return this->end1->getY();
  }

  template <class T>
  T LineSegment::getEnd1Z () {
    return this->end1->getZ();
  }

  template <class T>
  T LineSegment::getEnd2X () {
    return this->end2->getX();
  }

  template <class T>
  T LineSegment::getEnd2Y () {
    return this->end2->getY();
  }

  template <class T>
  T LineSegment::getEnd2Z () {
    return this->end2->getZ();
  }

  template <class T>
  T LineSegment::setEnd1X (T x) {
    return this->end1->setX();
  }

  template <class T>
  T LineSegment::setEnd1Y (T y) {
    return this->end1->setY();
  }

  template <class T>
  T LineSegment::setEnd1Z (T z) {
    return this->end1->setZ();
  }

  template <class T>
  T LineSegment::setEnd2X (T x) {
    return this->end2->setX();
  }

  template <class T>
  T LineSegment::setEnd2Y (T y) {
    return this->end2->setY();
  }

  template <class T>
  T LineSegment::setEnd2Z (T z) {
    return this->end2->setZ();
  }

  template <class T>
  T LineSegment::length () {
    T length;

    length = abs(this->end2->getX() - this->end1->getX());
    length += abs(this->end2->getY() - this->end1->getY());
    length += abs(this->end2->getZ() - this->end1->getZ());

    return (T)length;
  }

}

#endif
