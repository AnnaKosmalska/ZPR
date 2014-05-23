#include <vector>
#include <string>
#include <boost/python.hpp>

#include <Board.hpp>

using namespace boost::python;

class Game
{
private:
  std::vector<Board> boards;
  Game();
  Game(const Game&);
  Game& operator=(const Game&);

public:
  ~Game();
  static Game& getInstance();
  void addPlayer(string name);
  void startGame();
  void endGame();
  void removePlayer(string name);

  // struktura opisująca stan gry
  struct GameData
  {
    // czyja kolej
    int playerID;
    // stan gry
    // mogą być stany: start kolejki, wybieranie pierwszej karty, wybieranie drugiej karty,
    // koniec kolejki
    int state;
    // karty danego gracza
    std::vector<Tile> tiles;
  };
  

  
  
  
}
