#ifndef BOARD
#define BOARD

#include "Player.hpp"
#include "Tile.hpp"
#include <map>
#include <boost/python.hpp>


class Board
{
public:
  struct GameData
  {
    // stan gry
    int state;

    int currentPlayer;
  };
  
private:
    
  // lista graczy grajacych na danej planszy
  std::vector<Player> players;
  // zbior kart lezacych na stole; jezeli null - karta zostala zabrana
  // klucz - pozycja na stole (x,y), wartosc - wskaxnik na karte
  std::map<std::pair<int, int>, int> board;
  Tile firstPicked;
  Tile secondPicked;
  GameData gameData;
  int sizeX;
  int sizeY;

  Board();
  
  void clearBoard();

  void clearPlayers();

  int playersNumber();

  void initBoard();

  int randomTile(int range);

  // usuniecie pary z planszy (po wytypowaniu pary)
  void removePair();
  
  // zwraca karte z danego polozenia
  int getTile(int x, int y) const;


public: 
  
  ~Board();
  
  // dodaje gracza do gry
  // zwraca id gracza lub -1 jesli blad
  int addPlayer(std::string name);
  
  static Board& getInstance()
  {
    static Board instance;
    return instance;
  }  
   // wybranie karty przez gracza
  bool choose(int player, int x, int y);

  void startGame(int x, int y);

  void endGame();

  bool checkPair(int player);
  
};

int addPlayer(std::string name)
{
  return Board::getInstance().addPlayer(name);
}
bool choose(int player, int x, int y)
{
  return Board::getInstance().choose(player, x, y);
}
void startGame(int x, int y)
{
  Board::getInstance().startGame(x, y);
}
void endGame()
{
  Board::getInstance().endGame();
}
bool checkPair(int player)
{
  return Board::getInstance().checkPair(player);
}


BOOST_PYTHON_MODULE(model)
{
  boost::python::def("addPlayer", addPlayer);
  boost::python::def("choose", choose);
  boost::python::def("startGame", startGame);
  boost::python::def("endGame", endGame);
  boost::python::def("checkPair", checkPair);
}

#endif
