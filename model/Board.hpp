#ifndef BOARD
#define BOARD

#include "Player.hpp"
#include "Tile.hpp"
#include <map>
#include <boost/python.hpp>
#include <string>


class Board
{
  
private:
    
  // lista graczy grajacych na danej planszy
  std::vector<Player> players;
  // zbior kart lezacych na stole; jezeli null - karta zostala zabrana
  // klucz - pozycja na stole (x,y), wartosc - wskaxnik na karte
  std::map<std::pair<int, int>, int> board;
  int firstPicked;
  int secondPicked;
  int sizeX;
  int sizeY;

  int state;
  int currentPlayer;

  Board();
  
  void clearBoard();

  void clearPlayers();

  int playersNumber();

  void initBoard();



  // usuniecie pary z planszy (po wytypowaniu pary)
  void removePair();
  
  // zwraca karte z danego polozenia
  int getTile(int x, int y) const;


public: 
  
  ~Board();
  
  // dodaje gracza do gry
  // 1 - udalo sie dodac, 0 - blad (limit graczy)
  int addPlayer(std::string name);
  
  static Board& getInstance()
  {
    static Board instance;
    return instance;
  }  
   // wybranie karty przez gracza
  int choose(int player, int x, int y);

  void initGame(int x, int y);

  void endGame();

  bool checkPair(int player);

  int getCurrentPlayer()
  {
    return currentPlayer;
  }
  
};

int addPlayer(std::string name)
{
  return Board::getInstance().addPlayer(name);
}
int choose(int player, int x, int y)
{
  return Board::getInstance().choose(player, x, y);
}
void initGame(int x, int y)
{
  Board::getInstance().initGame(x, y);
}
void endGame()
{
  Board::getInstance().endGame();
}
bool checkPair(int player)
{
  return Board::getInstance().checkPair(player);
}
int getCurrentPlayer()
{
  return Board::getInstance().getCurrentPlayer();
}


BOOST_PYTHON_MODULE(model)
{
  boost::python::def("addPlayer", addPlayer);
  boost::python::def("choose", choose);
  boost::python::def("initGame", initGame);
  boost::python::def("endGame", endGame);
  boost::python::def("checkPair", checkPair);
  boost::python::def("getCurrentPlayer", getCurrentPlayer);
}

#endif
