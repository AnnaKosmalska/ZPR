CC=g++
CFLAGS=-lboost_system

test : main.o Board.o Player.o Deck.o Tile.o
	$(CC) $(CFLAGS) -o test main.o Board.o Player.o Deck.o Tile.o

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Board.o : ../Board.cpp ../Player.o ../Deck.o ../Tile.cpp
	$(CC) $(CFLAGS) -c ../Board.cpp
    
Player.o : ../Player.cpp ../Deck.cpp ../Tile.cpp
	$(CC) $(CFLAGS) -c ../Player.cpp
    
Deck.o : ../Deck.cpp ../Tile.cpp
	$(CC) $(CFLAGS) -c ../Deck.cpp
    
Tile.o : ../Tile.cpp
	$(CC) $(CFLAGS) -c ../Tile.cpp

del:
	rm *.o
	rm test
