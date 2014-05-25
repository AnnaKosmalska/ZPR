/**
   Klasa reprezentuje talię, jaką ma zdobytą gracz
 */

#ifndef DECK
#define DECK

#include <Tile.hpp>

class Deck
{
private:
  // lista kart zdobytych
  std::vector<Tile> deck;

public:
  // konstruktor
  Deck();
  // destruktor
  ~Deck();
  // dodanie karty do talii
  void addTile(Tile* tile);
  // liczba zdobytych par
  int getNumber();
  //
  std::vector<Tile*> getTiles() const;
}

#endif DECK
