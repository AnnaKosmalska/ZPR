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
  
  Player(string name);
  ~Player();
  void addToDeck(Tile* pair);


  void setName(string name);
  string getName();
  void setID(int ID);
  int getID();
  void setDeck(Deck* deck);
  Deck* getDeck();
  void addPair(Tile* pair);
  
}
