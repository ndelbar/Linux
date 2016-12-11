CC=g++
CFLAGS= -std=c++11 -Wall -w -g
INCLUDE:= -Iinclude/
SOURCE:= source/main.cpp \

OBJ= ./object/

all: ./release
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o ./release/myApp

./object:
	mkdir ./object

./release:
	mkdir ./release

clean:
	rm -rfv ./release
	rm -rfv ./object
