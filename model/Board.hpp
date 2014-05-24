#ifndef BOARD
#define BOARD

#include <Player.hpp>
#inlcude <Tile.hpp>


class Board
{
private:
  Board();
  Board(const Board&);
  
  // lista graczy grajacych na danej planszy
  std::vector<Player> players;
  // zbior kart lezacych na stole; jezeli null - karta zostala zabrana
  // klucz - pozycja na stole (x,y), wartosc - wskaxnik na karte
  std::map<TileOnBoard> board;
  PairOnBoard chosen;
  GameData* gameData;

public:

  struct GameData
  {
    // stan gry
    int state;

    int currentPlayer;
  }
  
  ~Board();
  
  // dodaje gracza do gry
  void addPlayer(string name);
  
  // usuwa gracza z gry
  void removePlayer(string name);

  // zwraca karte z danego polozenia
  Tile* getTile(Position position);

  // wybranie karty przez gracza
  bool choose(Position position, );

  // usuniecie pary z planszy (po wytypowaniu pary)
  bool removePair(PairOnBoard* pairToRemove);

  static Game& getInstance();

  void startGame();

  void endGame();

  

  
  
}

#endif
