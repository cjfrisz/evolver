#ifndef __POINT_H__
#define __POINT_H__

namespace evolver {

/*************************
 *   CLASS DECLARATION	 *
 *************************/
  template <class T>
  class Point {
  public:
    Point (void);
    ~Point (void);
    Point (const Point &original);

    T getX (void);
    T getY (void);
    T getZ (void);

    void setX (T x);
    void setY (T y);
    void setZ (T z);

  private:
    T x;
    T y;
    T z;
  };


/*************************
 *  CLASS DEFINITION	 *
 *************************/

  template <class T>
  Point<T>::Point () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  
  template <class T>
  Point<T>::~Point () {
    // Nothing to do yet
  }

  template <class T>
  Point<T>::Point (const Point &original) {
    // Nothing to do yet
  }

  template <class T>
  T Point<T>::getX (void) {
    return this->x;
  }

  template <class T>
  T Point<T>::getY (void) {
    return this->y;
  }

  template <class T>
  T Point<T>::getZ (void) {
    return this->z;
  }

  template <class T>
  void Point<T>::setX (T x) {
    this->x = x;

    return;
  }

  template <class T>
  void Point<T>::setY (T y) {
    this->y = y;

    return;
  }

  template <class T>
  void Point<T>::setZ (T z) {
    this->z = z;

    return;
  }

}

#endif
