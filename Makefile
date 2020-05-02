CXX = g++
CXXFLAGS = -Wall -ansi `xapian-config --cxxflags1` `xapian-config --libs` -pedantic -g -02

datastructures.o: datastructures.h datastructures.cpp

search.o: search.cpp

template.o: template.cpp

print.o: print.cpp

main.o: search.cpp

main: datastructures.o search.o template.o print.o main.o

.PHONY: clean
clean:
	rm main
