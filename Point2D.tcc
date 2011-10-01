#ifndef __POINT2D_H__
#define __POINT2D_H__

#include <cmath>

namespace evolver {

/*************************
 *   CLASS DECLARATION	 *
 *************************/
  template <typename T>
  class Point2D {
  public:
    Point2D (void);
    ~Point2D (void);
    Point2D (const Point2D<T> &original);

    Point2D operator= (const Point2D<T> &original);

    bool operator== (const Point2D<T> &other) const;
    bool operator!= (const Point2D<T> &other) const;

    T getX (void);
    T getY (void);

    void setX (T x);
    void setY (T y);

    T distance (const Point2D<T> &other) const;

  protected:
    void copyPoint2D (const Point2D &original);
    
  private:
    T x;
    T y;
    T z;
  };


/*************************
 *  CLASS DEFINITION	 *
 *************************/

  template <typename T>
  Point2D<T>::Point2D () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  
  template <typename T>
  Point2D<T>::~Point2D () {
    // Nothing to do yet
  }

  template <typename T>
  Point2D<T>::Point2D (const Point2D &original) {
    this->copyPoint2D();
  }

  template <typename T>
  Point2D<T> Point2D<T>::operator= (const Point2D<T> &original) {
    if (this != original) {
      this->copyPoint2D();
    }

    return *this;
  }

  template <typename T>
  bool Point2D<T>::operator== (const Point2D<T> &other) const {
    bool equal;

    if ((this->x == other->x) &&
	(this->y == other->y)) {
      equal = true;
    }
    else {
      equal = false;
    }

    return equal;
  }

  template <typename T>
  bool Point2D<T>::operator!= (const Point2D<T> &other) const {
    return !(*this == other);
  }

  template <typename T>
  T Point2D<T>::getX (void) {
    return this->x;
  }

  template <typename T>
  T Point2D<T>::getY (void) {
    return this->y;
  }

  template <typename T>
  void Point2D<T>::setX (T x) {
    this->x = x;

    return;
  }

  template <typename T>
  void Point2D<T>::setY (T y) {
    this->y = y;

    return;
  }

  template <typename T>
  T Point2D<T>::distance (const Point2D<T> &other) const {
    double dist;

    dist = pow((this->end2->getX() - this->end1->getX()), 2);
    dist += pow((this->end2->getY() - this->end1->getY()), 2);

    dist = sqrt(dist);

    return (T)dist;    
  }

  template <typename T>
  void Point2D<T>::copyPoint2D (const Point2D<T> &original) {
    this->x = original.x;
    this->y = original.y;

    return;
  }

}

#endif
