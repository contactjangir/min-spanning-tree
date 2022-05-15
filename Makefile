
all:
	g++ -std=c++11 -o prims prims.cpp
	g++ -std=c++11 -o kruskals kruskals.cpp

clean:
	rm -fr prims kruskals
