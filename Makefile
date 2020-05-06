CXX = g++
CXXFLAGS = -Wall -ansi -lboost_serialization -std=c++11 `xapian-config --cxxflags1` `xapian-config --libs` -pedantic -g

datastructures.o: datastructures.h datastructures.cpp

search.o: search.cpp

template.o: template.cpp

print.o: print.cpp

main.o: search.cpp

main: datastructures.o search.o template.o print.o main.o

.PHONY: clean
clean:
	rm main
