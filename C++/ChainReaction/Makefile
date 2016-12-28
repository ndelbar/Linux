CC = g++

CFLAGS= -std=c++11 -Wall -w -g

INCLUDE:= -Iinclude/

SOURCE := source/Main.cpp\
	  source/Grid.cpp

all: ./release
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o ./release/myApp

./release:
	mkdir ./release

clean:
	rm -rfv ./release
