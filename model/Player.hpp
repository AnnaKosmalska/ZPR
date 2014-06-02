
#ifndef PLAYER
#define PLAYER

#include <string>
#include "Deck.hpp"

class Player
{
private:
  
  std::string name;
  int ID;
  int score;
  Deck* deck;

  

public:
  
  Player(std::string name, int ID);
  ~Player();
  void addToDeck(int newTile);
  std::string getName() const;
  int getID() const;
  Deck* getDeck() const;
  int getScore() const;
  void incScore(int points);
  
};

#endif
