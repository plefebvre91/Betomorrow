#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <complex>
class Vector {
public:
  /**
   * Default constructor
   */
  Vector():_x(0), _y(0) {}


  /**
   * Constructor
   * \param a X-coordinate
   * \param b Y-coordinate
   */
  Vector(float a, float b): _x(a), _y(b) {}
  

  /**
   * Copy constructor
   */
  Vector(const Vector& v) {
    _x = v.x();
    _y = v.y();
  }

  
  /**
   * Assignation operator
   */
  Vector& operator=(const Vector& a) {
    _x = a.x();
    _y = a.y();

    return *this;
  }


  /**
   * Addition operator
   */
  Vector operator+(const Vector& a) const {
    Vector v(_x + a.x(), 
	     _y + a.y());

    return v;
  }


  /**
   * Substraction operator
   */
  Vector operator-(const Vector& a) const {
    Vector v(_x - a.x(), 
	     _y - a.y());

    return v;
  }

  
  /**
   * Equality operator
   */
  bool operator==(const Vector& a) const {
    return ((_x == a.x()) && (_y == a.y()));
  }
  

  /**
   * Getter for first coordinate
   */
  inline int x() const {
    return _x;
  }


  /**
   * Getter for second coordinate
   */
  inline int y() const {
    return _y;
  }


  /**
   * Getter for a reference to the first coordinate
   */
  inline int& x() {
    return _x;
  }


  /**
   * Getter for a reference to the second coordinate
   */
  inline int& y() {
    return _y;
  }

  
  /** 
   * Hashes the vector (x,y) into the 64 bits-integer whith
   * LSB = y and MSB = x
   */
  uint64_t hash() const {
    uint64_t h = _x & 0xffff;
    uint64_t y = _y & 0xffff;

    h = h << 32;
    h |= y;

    return h;
  }
  
private:
  int _x;
  int _y;
};

typedef Vector Point;

#endif
