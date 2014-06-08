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
#include <string>
#include <boost/thread/mutex.hpp>
#include "MyException.hpp"

/*! \class Board
  \brief reprezentuje plansze gry

  Obiekt klasy Board wystepujem tylko jeden w calej grze, wobec czego zostal zrealizowany zgodnie ze wzorcem singletona.
*/
class Board
{
  friend class Test;
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
  /*!<najwyzszy wynik w grze*/
  boost::mutex initMutex;
  /*!<mutex sluzacy ochronie inicjowania gry (krytyczne aby wykonal je tylko jeden gracz)*/

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
  
  /*! \brief usuniecie pary z planszy firstPicked i secondPicked
   */
  void removePair();
  /*! \brief sprawdzenie karty

    \return id karty
    \param x wspolrzedna X karty
    \param y wspolrzedna Y karty
  */
  int getTile(int x, int y) const;
  /*! \brief nastepny gracz
   */
  int nextPlayer();

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
  int getScore(int player);
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
  std::string getName(int player);
  /*! \brief czy gracz jest zwyciezca

    \return zwyciestwo
  */
  int getWinner(int player);
  /*! \brief funkcja wylaczajaca gracza z rozgrywki
   */
  int playerDead(int player);
  
};

#endif
