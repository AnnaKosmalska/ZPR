/**
   implementacja klasy Tile
*/

#include "Tile.hpp"

Tile::Tile()
{
  ID = 0;
}

Tile::Tile(int _ID)
{
  ID = _ID;
}

Tile::~Tile()
{}

int Tile::getID() const
{
  return ID;
}

bool Tile::operator==(const Tile& tile) const
{
  return getID() == tile.getID();
}
