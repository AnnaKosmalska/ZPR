#ifndef BOARD
#define BOARD

#include "Player.hpp"
#include "Tile.hpp"
#include "Constants.hpp"
#include <map>
#include <boost/python.hpp>


class Board
{
public:
  struct GameData
  {
    // stan gry
    int state;
    //punktacja graczy
    int player1Score;
    int player2Score;
    int player3Score;
    int player4Score;
    //odkryte klocki
    int pickedFirst;
    int pickedSecond;
    // akktualny gracz
    int currentPlayer;
  };
  GameData gameData;
  
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

  int nextPlayer();

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
  int choose(int player, int x, int y);

  bool initGame(int player, int x, int y);

  void endGame();

  GameData getGameData() const;

  int playerReady(int player, int decision);
  
};

int playerReady(int player, int decision)
{
  return Board::getInstance().playerReady(player, decision);
}

Board::GameData getGameData()
{
  return Board::getInstance().getGameData();
}

int addPlayer(std::string name)
{
  return Board::getInstance().addPlayer(name);
}
int choose(int player, int x, int y)
{
  return Board::getInstance().choose(player, x, y);
}
bool initGame(int player, int x, int y)
{
  return Board::getInstance().initGame(player, x, y);
}
void endGame()
{
  Board::getInstance().endGame();
}


BOOST_PYTHON_MODULE(model)
{
  boost::python::def("addPlayer", addPlayer);
  boost::python::def("choose", choose);
  boost::python::def("initGame", initGame);
  boost::python::def("endGame", endGame);
}

#endif
