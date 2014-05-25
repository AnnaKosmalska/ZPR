
#include "Board.hpp"
#inlcude "Constants.hpp"

Board::Board()
{
  gameData.state = 0;
  gameData.currentPlayer = 0;
}

Board::~Board()
{
  clearBoard();
  clearPlayers();
}

Board::clearBoard()
{
  gameData.state = 0;
  gameData.currentPlayer = 0;
  board.clear();
}

Board::clearPlayers()
{
  gameData.currentPlayer = 0;
  players.clear();
}

bool Board::addPlayer(std::string name)
{
  if(playersNumber() >= MAX_PLAYERS)
    return false;
  Player* newPlayer = new Player(name, playersNumber());
  players.push_back(newPlayer);
  return true;
}

void Board::removePlayer(int ID)
{
  Player deletedPlater = players.pop_back();
}
