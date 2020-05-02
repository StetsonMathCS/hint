CXXFLAGS=-Wall -std=c++11 -lboost_serialization

main: main.cpp
	g++ main.cpp $(CXXFLAGS) -o main

.PHONY: clean
clean:
	rm main

