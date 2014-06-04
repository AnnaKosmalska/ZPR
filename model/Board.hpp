/*! \file Board.hpp
  \brief Plik naglowkowy klasy Board reprezentujacej plansze gry.

  Zawiera takze funkcje do interfejsu dla modulu pythona.
  \author Anna Wujek
*/

#ifndef BOARD
#define BOARD

#include "Player.hpp"
#include "Tile.hpp"
#include <map>
#include <boost/python.hpp>
#include <string>

/*! \class Board
  \brief reprezentuje plansze gry

  Obiekt klasy Board wystepujem tylko jeden w calej grze, wobec czego zostal zrealizowany zgodnie ze wzorcem singletona.
*/
class Board
{
  
private:
    
  std::vector<Player> players;
  /*!<lista graczy grajacych na danej planszy*/
  std::map<std::pair<int, int>, int> board;
  /*!<zbior kart lezacych na stole; jezeli null - karta zostala zabrana. Klucz - pozycja na stole (x,y), wartosc - wskaxnik na karte*/
  int firstPicked;
  /*!<pierwsza karta podniesiona rzez pierwszego gracza*/
  int secondPicked;
  /*!<druga karta podniesiona przez aktualnego gracza*/
  int firstX;
  /*!<wspolrzedna X pierwszej karty*/
  int firstY;
  /*!<wspolrzedna Y pierwszej podniesionej karty*/
  int secondX;
  /*!<wspolrzedna X drugiej podniesionej karty*/
  int secondY;
  /*!<wspolrzedna Y drugiej podniesionej karty*/
  int sizeX;
  /*!<wymiar X planszy*/
  int sizeY;
  /*!<wymiar Y planszy*/
  int state;
  /*!<stan gry*/
  int currentPlayer;
  /*!<aktualny gracz*/
  int all;
  /*!<liczba kart pozostalych na stole*/
  int winner;
  //*!<najwyzszy wynik w grze*

  /*! \brief konstruktor

    konstruktor prywatny
  */
  Board();
  /*! \brief czyszczenie planszy

    usuniecie wszystkich kart z planszy
  */
  void clearBoard();
  /*! \brief czyszczenie graczy

    usuniecie wszystkich graczy z gry
  */
  void clearPlayers();
  /*! \brief ilu graczy jest w grze

    \return liczba graczy
  */
  int playersNumber();
  /*! \brief inicjalizacja planszy

    rozlozenie kart na planszy
  */
  void initBoard();
  /*! \brief sprawdzenie karty

    \return id karty
    \param x wspolrzedna X karty
    \param y wspolrzedna Y karty
  */
  int getTile(int x, int y) const;
  /*! \brief usuniecie pary z planszy firstPicked i secondPicked
   */
  void removePair();

public: 
  /*! \brief destruktor

    usuwa graczy oraz karty z planszy
  */
  ~Board();
  /*! \brief dodanie gracza

    dodaje gracza do gry sprawdzajac, czy jest to mozliwe

    \return id_gracza lub kod bledu
    \param name nazwa gracza
  */
  int addPlayer(std::string name);
  /*! \brief pobranie instancji obiektu Board

    realizacja wzorca singleton zgodnie z wykladem

    \return instanca planszy
  */
  static Board& getInstance()
  {
    static Board instance;
    return instance;
  }  
  /*! \brief wybranie karty przez gracza

    \return id karty lub kod bledu
    \param player id gracza
    \param x wsporzedna X karty
    \param y wspolrzedna Y karty
  */
  int choose(int player, int x, int y);
  /*! \brief inicjacja gry

    inicjacja gry, obejmujaca ustawienie wymiarow planszy oraz jej wypelnienie

    \return status
    \param x wymiar X planszy
    \param y wymiar Y planszy
  */    
  int initGame(int x, int y);
  /*! \brief zakonczenie gry
   */
  void endGame();
  /*! \brief zakonczenie tury

    zakonczenie tury gracza (informacja, ze kolejny gracz moze zaczac swoja ture)

    \return id kolejnego gracza
  */
  int endTurn();
  /*! \brief pobranie aktualnego gracza

    \return id aktualnego gracza
   */
  int getCurrentPlayer()
  {
    return currentPlayer;
  }
  /*! \brief pobranie stanu gry

    \return stan gry
   */
  int getState()
  {
    return state;
  }
  /*! \brief pobranie pierwszej podniesionej karty

    \return id karty
   */
  int getFirstPicked()
  {
    return firstPicked;
  }
  /*! \brief pobranie X pierwszej podniesionej karty

    \return wspolrzedna X
   */
  int getFirstX()
  {
    return firstX;
  }
  /*! \brief pobranie Y pierwszej podniesionej karty

    \return wspolrzedna Y
   */
  int getFirstY()
  {
    return firstY;
  }
  /*! \brief pobranie drugiej podniesionej karty

    \return id karty
   */
  int getSecondPicked()
  {
    return secondPicked;
  }
  /*! \brief pobranie X drugiej podniesionej karty

    \return wspolrzedna X
   */
  int getSecondX()
  {
    return secondX;
  }
  /*! \brief pobranie Y drugiej podniesionej karty

    \return wspolrzedna Y
   */
  int getSecondY()
  {
    return secondY;
  }
  /*! \brief pobranie wyniku gracza

    \return wynik gracza
    \param score id gracza
   */
  int getScore(int player)
  {
    return players[player].getScore();
  }
  /*! \brief pobranie wymiaru plaszy X

    \return X planszy
  */
  int getSizeX()
  {
    return sizeX;
  }
  /*! \brief pobranie wymiaru planszy Y

    \return Y planszy
  */
  int getSizeY()
  {
    return sizeY;
  }
  /*! \brief pobranie nazwy gracza

    \return nazwa gracza
  */
  std::string getName(int player)
  {
    return players[player].getName();
  }
  /*! \brief czy gracz jest zwyciezca

    \return zwyciestwo
  */
  int getWinner(int player);
  
};

/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int addPlayer(std::string name)
{
  return Board::getInstance().addPlayer(name)+1;
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int choose(int player, int x, int y)
{
  return Board::getInstance().choose(player-1, x, y);
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int initGame(int x, int y)
{
  return Board::getInstance().initGame(x, y);
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
void endGame()
{
  Board::getInstance().endGame();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getCurrentPlayer()
{
  return Board::getInstance().getCurrentPlayer()+1;
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getState()
{
  return Board::getInstance().getState();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstPicked()
{
  return Board::getInstance().getFirstPicked();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstX()
{
  return Board::getInstance().getFirstX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getFirstY()
{
  return Board::getInstance().getFirstY();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondPicked()
{
  return Board::getInstance().getSecondPicked();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondX()
{
  return Board::getInstance().getSecondX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSecondY()
{
  return Board::getInstance().getSecondY();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getScore(int player)
{
  return Board::getInstance().getScore(player-1);
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int endTurn()
{
  return Board::getInstance().endTurn()+1;
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSizeX()
{
  return Board::getInstance().getSizeX();
}
/*! \brief funkcja sluzaca do komunikacji z interfejsem modulu pythona
 */
int getSizeY()
{
  return Board::getInstance().getSizeY();
}
/*! \brief modul pythona sluzacy do komunikacji z serwerem
 */
BOOST_PYTHON_MODULE(model)
{
  boost::python::def("addPlayer", addPlayer);
  boost::python::def("choose", choose);
  boost::python::def("initGame", initGame);
  boost::python::def("endGame", endGame);
  boost::python::def("getCurrentPlayer", getCurrentPlayer);
  boost::python::def("getState", getState);
  boost::python::def("getFirstPicked", getFirstPicked);
  boost::python::def("getFirstX", getFirstX);
  boost::python::def("getFirstY", getFirstY);
  boost::python::def("getSecondPicked", getSecondPicked);
  boost::python::def("getSecondX", getSecondX);
  boost::python::def("getSecondY", getSecondY);
  boost::python::def("endTurn", endTurn);
  boost::python::def("getScore", getScore);
  boost::python::def("getSizeX", getSizeX);
  boost::python::def("getSizeY", getSizeY);
}

#endif
