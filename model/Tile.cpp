/**
   implementacja klasy Tile
*/

#include <Tile.hpp>

Tile::Tile(int ID)
{
  this.ID = ID;
}

Tile::~Tile()
{}

int Tile::getID()
{
  return ID;
}

bool Tile::operator=(const Tile& tile) const
{
  return getID() == tile.getID();
}
