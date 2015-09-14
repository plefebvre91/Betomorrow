CXX=g++
CFLAGS=-Wall -Wextra -O3 --std=c++11

find_square: main.o FindSquare.o
	$(CXX) $(CFLAGS) $^ -o $@


FindSquare.o: FindSquare.cpp Vector.hpp
	$(CXX) -c $(CFLAGS) $^


main.o: main.cpp
	$(CXX) -c $(CFLAGS) $^

clean:
	@rm *.o *.gch find_square
