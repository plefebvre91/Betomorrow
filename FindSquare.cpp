#include "FindSquare.hpp"

FindSquare::FindSquare(const char* filename):map(),point() {
  // Open the file
  std::ifstream fp(filename, std::ios::in);
  
  if(!fp) {
    std::cerr << "Unable to read file!" << std::endl;
    exit(0);
  }
  
  int x,y;

  // Read the file and store point in the map and the array
  while(!fp.eof()) {
    fp >> x >> y;

    Point p(x,y);
    point.push_back(p);
    map[p.hash()] = true;
  }
  
  // Close the file
  fp.close();
}


bool FindSquare::searchForSquare() {
  // Result
  bool aSquareHasBeenFound = false;

  // Scan all pair of points  
  for(auto a : point) {
    for(auto b : point) {
      // Check if the pair is part of a sqaure
      aSquareHasBeenFound = check(a, b);
      
      // Return true if a square has been found...
      if(aSquareHasBeenFound) {
	return true;
      }
    }
  }
  // ... or false otherwise
  return false;
}


void FindSquare::run() {
  // Result
  bool aSquareHasBeenFound = searchForSquare();
  
  const char* msg = (aSquareHasBeenFound)? 
    MSG_SQUARE_FOUND:MSG_SQUARE_NOT_FOUND;
  
  // Display a message
  std::cout << msg << std::endl;
}


bool FindSquare::existsInMap(const Point& a) const {
  return (map.count(a.hash()) > 0);
}


bool FindSquare::check(const Point& a, const Point& b) const {
// Works only if a different from b
  if(a==b){
    return false;
  }

  Vector u = b - a;
  Vector v(-u.y(), u.x());
  
  Point A1 = a + v;
  Point B1 = b + v;

  // Return true if A1,B1 exist and  are part of a square with a,b
  if(existsInMap(A1) && existsInMap(B1)) {
    printSquare(a,b,A1,B1);
    return true;
  }
  
  Point A2 = a - v;
  Point B2 = b - v;
  
  // Return true if A2,B2 exist and  are part of a square with a,b
  if(existsInMap(A2) && existsInMap(B2)) {
    printSquare(a,b,A2,B2);
    return true;
  }

  // False othewise
  return false;
}


void FindSquare::printSquare(const Point& a, const Point& b, const Point& c, const Point& d) const {
  std::cout << "[" << a.x() << ","<< a.y() << "] ";
  std::cout << "[" << b.x() << ","<< b.y() << "] ";
  std::cout << "[" << c.x() << ","<< c.y() << "] ";
  std::cout << "[" << d.x() << ","<< d.y() << "]" << std::endl;
}
