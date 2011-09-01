#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace evolver {

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

}

#endif
