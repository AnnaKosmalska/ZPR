#ifndef BOARD
#define BOARD

#include <Player.hpp>
#inlcude <Tile.hpp>


class Board
{
private:
  Board();  
  // lista graczy grajacych na danej planszy
  std::vector<Player> players;
  // zbior kart lezacych na stole; jezeli null - karta zostala zabrana
  // klucz - pozycja na stole (x,y), wartosc - wskaxnik na karte
  std::map<position, unsigned> board;
  Tile firstPicked;
  Tile secondPicked;
  GameData gameData;
  int size;

public:
  struct GameData
  {
    // stan gry
    int state;

    int currentPlayer;
  }
  
  ~Board();
  
  // dodaje gracza do gry
  // 1 - udalo sie dodac, 0 - blad (limit graczy)
  bool addPlayer(std::string name);

  // zwraca karte z danego polozenia
  unsigned getTile(Position position);

  // wybranie karty przez gracza
  bool choose(Position position);

  // usuniecie pary z planszy (po wytypowaniu pary)
  void removePair(PairOnBoard pairToRemove);

  static Board& getInstance();

  void startGame();

  void endGame();

  void clearBoard();

  void clearPlayers();

  int playersNumber();

  void initBoard(int sizeOfBoard);

  
  
}

#endif
