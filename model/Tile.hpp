/**
   Klasa reprezentująca jedną kartę w grze.
 */

#ifndef TILE
#define TILE

typedef std::pair<unsigned, unsigned> Position;
typedef std::pair<Position, unsigned> TileOnBoard;
typedef std::pair<Position, Position> PairOnBoard;

class Tile
{
private:
  // identyfikator karty - unikalny
  int ID;

public:

  Tile(int ID);
  ~Tile();
  int getID();
  bool operator=(const Tile& tile) const;
}

#endif
