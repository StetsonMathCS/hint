CXXFLAGS=-Wall -std=c++11 -lboost_serialization

main: serializedSTL.cpp
	g++ serializedSTL.cpp $(CXXFLAGS) -o main

.PHONY: clean
clean:
	rm main

