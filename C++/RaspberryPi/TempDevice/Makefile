CC = g++ -std=c++11
CFLAGS= -lwiringPi -lwiringPiDev -pthread
DCC = g++ -g -std=c++11
INCLUDE:= -Iinclude/
SOURCE := source/Main.cpp

all: ./release
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o ./release/myApp 

debug:
	$(DCC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o ./debug/myAppD

clean:
	rm -rfv ./release
	clear

./release:
	mkdir ./release


