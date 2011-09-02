#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace evolver {

/*************************
 *   CLASS DECLARATION	 *
 *************************/
  template <class T>
  class Coordinates {
  public:
    Coordinates (void);
    ~Coordinates (void);
    Coordinates (const Coordinates &original);

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
  Coordinates<T>::Coordinates () {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  
  template <class T>
  Coordinates<T>::~Coordinates () {
    // Nothing to do yet
  }

  template <class T>
  Coordinates<T>::Coordinates (const Coordinates &original) {
    // Nothing to do yet
  }

  template <class T>
  T Coordinates<T>::getX (void) {
    return this->x;
  }

  template <class T>
  T Coordinates<T>::getY (void) {
    return this->y;
  }

  template <class T>
  T Coordinates<T>::getZ (void) {
    return this->z;
  }

  template <class T>
  void Coordinates<T>::setX (T x) {
    this->x = x;

    return;
  }

  template <class T>
  void Coordinates<T>::setY (T y) {
    this->y = y;

    return;
  }

  template <class T>
  void Coordinates<T>::setZ (T z) {
    this->z = z;

    return;
  }

}

#endif
