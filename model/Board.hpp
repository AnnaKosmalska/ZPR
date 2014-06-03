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
  int firstX;
  int firstY;
  int secondPicked;
  int secondX;
  int secondY;
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

  int endTurn();

  int getCurrentPlayer()
  {
    return currentPlayer;
  }
  int getState()
  {
    return state;
  }
  int getFirstPicked()
  {
    return firstPicked;
  }
  int getFirstX()
  {
    return firstX;
  }
  int getFirstY()
  {
    return firstY;
  }
  int getSecondPicked()
  {
    return secondPicked;
  }
  int getSecondX()
  {
    return secondX;
  }
  int getSecondY()
  {
    return secondY;
  }
  int getScore(int player)
  {
    return players[player].getScore();
  }
  
};

int addPlayer(std::string name)
{
  return Board::getInstance().addPlayer(name)+1;
}
int choose(int player, int x, int y)
{
  return Board::getInstance().choose(player-1, x, y);
}
void initGame(int x, int y)
{
  Board::getInstance().initGame(x, y);
}
void endGame()
{
  Board::getInstance().endGame();
}
int getCurrentPlayer()
{
  return Board::getInstance().getCurrentPlayer()+1;
}
int getState()
{
  return Board::getInstance().getState();
}
int getFirstPicked()
{
  return Board::getInstance().getFirstPicked();
}
int getFirstX()
{
  return Board::getInstance().getFirstX();
}
int getFirstY()
{
  return Board::getInstance().getFirstY();
}
int getSecondPicked()
{
  return Board::getInstance().getSecondPicked();
}
int getSecondX()
{
  return Board::getInstance().getSecondX();
}
int getSecondY()
{
  return Board::getInstance().getSecondY();
}
int getScore(int player)
{
  return Board::getInstance().getScore(player-1);
}

int endTurn()
{
  return Board::getInstance().endTurn()+1;
}

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
}

#endif
