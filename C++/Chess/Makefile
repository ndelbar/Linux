CC = g++

CFLAGS= -std=c++11 -Wall -w -g

INCLUDE:= -Iinclude/

SOURCE := source/Main.cpp \
					source/Board.cpp \
					source/Cell.cpp \
					source/ChessGame.cpp \

all: ./release
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o ./release/myApp

./release:
	mkdir ./release

clean:
	rm -rfv ./release
