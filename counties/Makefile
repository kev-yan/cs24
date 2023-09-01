CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror
CXX      = g++

.PHONY: all clean

all: test

test: test.o CountyMap.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp CountyMap.h CountyMap.cpp County.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

CountyMap.o: CountyMap.cpp CountyMap.h County.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test test.o CountyMap.o