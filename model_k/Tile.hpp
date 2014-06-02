/**
   Klasa reprezentująca jedną kartę w grze.
 */

#ifndef TILE
#define TILE

class Tile
{
private:
  // identyfikator karty - unikalny
  int ID;

public:

  Tile();
  Tile(int ID);
  ~Tile();
  int getID() const;
  bool operator==(const Tile& tile) const;
};

#endif
