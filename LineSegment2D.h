#ifndef __LINESEGMENT2D_H__
#define __LINESEGMENT2D_H__

#include <cmath>

namespace evolver {

  template <class T> class Point2D;
  
  template <class T>
  class Linesegment2D {
  public:
    Linesegment2D (void);
    ~Linesegment2D (void);
    Linesegment2D (const Linesegment2D &original);
    
    Linesegment2D &operator= (const Linesegment2D &original);

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

    bool intersects (const Linesegment2D &other) const;

  private:
    Point2D<T> *end1;
    Point2D<T> *end2;
  };

  template <class T>
  Linesegment2D::Linesegment2D () {
    this->end1 = new Point2D<T>;
    this->end2 = new Point2D<T>;
  }

  template <class T>
  Linesegment2D::~Linesegment2D () {
    delete end1;
    delete end2;
  }

  template <class T>
  Linesegment2D::Linesegment2D (const Linesegment2D &original) {
    if (this != &original) {
      *(this->end1) = *(original.end1);
      *(this->end2) = *(original.end2);
    }

    return *this;
  }

  template <class T>
  T Linesegment2D::getEnd1X () {
    return this->end1->getX();
  }

  template <class T>
  T Linesegment2D::getEnd1Y () {
    return this->end1->getY();
  }

  template <class T>
  T Linesegment2D::getEnd1Z () {
    return this->end1->getZ();
  }

  template <class T>
  T Linesegment2D::getEnd2X () {
    return this->end2->getX();
  }

  template <class T>
  T Linesegment2D::getEnd2Y () {
    return this->end2->getY();
  }

  template <class T>
  T Linesegment2D::getEnd2Z () {
    return this->end2->getZ();
  }

  template <class T>
  T Linesegment2D::setEnd1X (T x) {
    return this->end1->setX();
  }

  template <class T>
  T Linesegment2D::setEnd1Y (T y) {
    return this->end1->setY();
  }

  template <class T>
  T Linesegment2D::setEnd1Z (T z) {
    return this->end1->setZ();
  }

  template <class T>
  T Linesegment2D::setEnd2X (T x) {
    return this->end2->setX();
  }

  template <class T>
  T Linesegment2D::setEnd2Y (T y) {
    return this->end2->setY();
  }

  template <class T>
  T Linesegment2D::setEnd2Z (T z) {
    return this->end2->setZ();
  }

  template <class T>
  T Linesegment2D::length () {
    // Take advantage of Point2D's built-in distance method
    return this->end1->distance(*(this->end2));
  }

  template <class T>
  bool Linesegment2D::intersects (const Linesegment2D &other) const {
    
  }

  template <class T>
  void Linesegment2D::copyLinesegment2D (const Linesegment2D &original) {
    *(this->end1) = *(original.end1);
    *(this->end2) = *(original.end2);

    return;
  }

}

#endif
