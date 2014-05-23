/**
   Klasa reprezentująca jedną kartę w grze.
 */

#ifndef TILE
#define TILE

typedef std::pair<int, int> Position;
typedef std::pair<Position, Tile*> TileOnBoard;
typedef std::pair<TileOnBoard, TileOnBoard> PairOnBoard;

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
