/**
   Klasa reprezentuje talię, jaką ma zdobytą gracz
 */

#ifndef DECK
#define DECK

#include "Tile.hpp"
#include <vector>

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
  void addTile(int newTile);
  // liczba zdobytych par
  int getNumber() const;
  //
  std::vector<int> getTiles() const;
};

#endif
