#include <iostream>
#include "FindSquare.hpp"

int main(int argc, char** argv) {
  
  // Display help if filename was not given
  if(argc < 2) {
    std::cout << "Usage: find_square <filename>" << std::endl;
    return 0;
  }

  const char* filename = argv[1];

  // Starts the program
  FindSquare app(filename);
  app.run();

  return 0;
}
