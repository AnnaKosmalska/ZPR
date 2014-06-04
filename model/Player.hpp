/*! \file Player.hpp
  \brief Plik naglowkowy klasy Player reprezentujacej gracza.

  \author Anna Wujek
*/
#ifndef PLAYER
#define PLAYER

#include <string>
#include "Deck.hpp"

/*! \class Player
  \brief reprezentuje gracza
*/
class Player
{
private:
  std::string name;
  /*!<nazwa gracza*/
  int ID;
  /*!<id gracza*/
  int score;
  /*!<wynik gracza*/
  Deck deck;
  /*!<karty zdobyte przez gracza*/ 

public:
  /*! \brief konstruktor
    \param name nazwa gracza
    \param ID id gracza
   */
  Player(std::string name, int ID);
  /*! \brief destruktor
   */
  ~Player();
  /*! \brief dodanie karty zdobytej przez gracza

    \param newTile nowa karta
   */
  void addToDeck(int newTile);
  /*! \brief pobranie id gracza
    
    \return id gracza
  */
  int getID() const;
  /*! \brief pobranie kart gracza

    \return karty gracza
  */
  Deck getDeck() const;
  /*! \brief pobranie wyniku gracza

    \return wynik
  */
  int getScore() const;
  /*! \brief dodanie graczowi punktow
    \param points liczba punktow
  */
  void incScore(int points);
  /*! \brief pobranie nazwy gracza

    \return nazwa gracza
  */
  std::string getName()

  {
    return name;
  }
};

#endif
