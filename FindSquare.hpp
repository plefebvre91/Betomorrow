#ifndef FIND_SQUARE_HPP
#define FIND_SQUARE_HPP

#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <complex>
#include "Vector.hpp"

#define MSG_SQUARE_FOUND     "A square has been found"
#define MSG_SQUARE_NOT_FOUND "No square"

class FindSquare {
public:
  /**
   * Constructor
   * \param filename : file where points are stored
   */
  FindSquare(const char* filename);

  /**
   * Start the program
   */
  void run();
  
private:
  /**
   * Search for 2 others points which complete the square
   * \param a a point from the given set
   * \param b another point from the given set
   * \return true if points c,d have been found and (abcd) is a square 
   */
  bool check(const Point& a, const Point& b) const;

  /**
   * Return true if the given point is the given set
   * \param a a point
   * \retun true if a is in the set
   */
  bool existsInMap(const Point& a) const;

  /**
   * Scan pair of points a search for a square
   * \return true if a square has been found
   */
  bool searchForSquare();

  /**
   * Print the square coordinates
   */
  void printSquare(const Point& a, const Point& b, const Point& c, const Point& d) const;
  

  std::map<uint64_t,bool> map;
  std::vector<Point> point;
};
#endif
