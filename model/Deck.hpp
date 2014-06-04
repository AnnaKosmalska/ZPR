/*! \file Deck.hpp
  \brief Plik naglowkowy klasy Deck reprezentujacej zbior kart

  \author Anna Wujek
*/

#ifndef DECK
#define DECK

#include "Tile.hpp"
#include <vector>

/*! class Deck
  \brief reprezentuje talie kart
*/
class Deck
{
private:
  std::vector<Tile> deck;
  /*!<lista kart*/
public:
  /*! \brief konstruktor
   */
  Deck();
  /*! \brief destruktor
   */
  ~Deck();
  /*! \brief dodanie karty do talii
    \param newTile id nowej karty
  */
  void addTile(int newTile);
  /*! \brief pobranie liczby zdobytych par
    \return liczba par
  */
  int getNumber() const;
  /*! \brief pobranie zdobytych par
    \return zdobyte pary
  */
  std::vector<int> getTiles() const;
};

#endif
