
#ifndef PLAYER
#define PLAYER

#include <Deck.hpp>

class Player
{
private:
  
  string name;
  int ID;
  int score;
  Deck* deck;

  void incScore(int points);

public:
  
  Player(string name, int ID);
  ~Player();
  void addToDeck(Tile* pair);
  string getName();
  int getID();
  Deck* getDeck();
  int getScore();
  
}

#endif
