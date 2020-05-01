CXX=g++
CXXFLAGS=-g -Wall -ansi `xapian-config --cxxflags` `xapian-config --libs`

all: main

main.o: search.cpp
	$(CXX) $(CXXFLAGS) -c search.cpp

main: search.o
	$(CXX) $(CXXFLAGS) -o search search.o
