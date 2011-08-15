#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace evolver {

  class Coordinates {
  public:
    Coordinates (void);
    ~Coordinates (void);
    Coordinates (const Coordinates &original);

    int getX (void);
    int getY (void);
    int getZ (void);

    void setX (int x);
    void setY (int y);
    void setZ (int z);

  private:
    int x;
    int y;
    int z;
  }

}

#endif
