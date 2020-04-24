


run: urls.cpp
	g++ -o run -Wall urls.cpp -lcurl -ljsoncpp


.PHONY : clean

clean:
	rm run

