

#include <Deck.hpp>

Deck::Deck()
{
  
}

Deck::~Deck()
{}

void Deck::addTile(Tile* tile)
{
  deck.push_back(tile);
}

int Deck::getNumber()
{
  return deck.size();
}

std::vector<Tile*> Deck::getTiles() const
{
  std::vector<Tile*> tiles;
  for(std::vector<Tile*>::const_iterator it = deck.begin(); it != deck.end(); ++it)
    {
      tiles.push_back(*it);
    }
  return tiles;
}
