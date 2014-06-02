

#include "Deck.hpp"

Deck::Deck()
{
  
}

Deck::~Deck()
{}

void Deck::addTile(int newTile)
{
  deck.push_back(Tile(newTile));
}

int Deck::getNumber() const
{
  return deck.size();
}

std::vector<int> Deck::getTiles() const
{
  std::vector<int> tiles;
  for(int i = 0; i < getNumber(); ++i)
    {
      tiles.push_back(deck[i].getID());
    }
  return tiles;
}
