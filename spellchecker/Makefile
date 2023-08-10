CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

# Magic Variables!
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#  $@ is the name of the target
#  $+ is a list of all the dependencies
#  $< is the first dependency

all: test

test: test.o Heap.o Point.o WordList.o main.o
	${CXX} $(CXXFLAGS) -o $@ $+

test.o: test.cpp Heap.h Point.h WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Heap.o: Heap.cpp Heap.h Point.h WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

WordList.o: WordList.cpp Heap.h Point.h WordList.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f test test.o Heap.o WorldList.o Point.o

