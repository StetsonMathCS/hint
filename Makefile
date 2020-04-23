output: main.o stats.o
	g++ main.o stats.o -o output
main.o: main.cpp
	g++ -c main.cpp
stats.o: stats.cpp stats.h
	g++ -c stats.cpp

clean: 
	rm*.o output
