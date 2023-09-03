CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror
CXX      = g++

.PHONY: all clean

all: main

main: main.o CountyMap.o
	${CXX} $(CXXFLAGS) -o $@ $+

main.o: main.cpp CountyMap.h CountyMap.cpp County.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

CountyMap.o: CountyMap.cpp CountyMap.h County.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test test.o CountyMap.o