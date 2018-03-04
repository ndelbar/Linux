CC = g++ -std=c++11 Main.cpp
DCC = g++ -g -std=c++11 Main.cpp
SOURCE := Main.cpp


all:
	$(CC) -o myApp -lwiringPi -lwiringPiDev

debug:
	$(DCC) -o myAppD

clean:
	rm myApp -f
	clear