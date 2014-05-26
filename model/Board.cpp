
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
  players.push_back(newPlayer&);
  return true;
}

Tile* Board::getTile(Position position)
{
  return board.find(position);
}

bool Board::choose(Position position)
{
  if(gameData.state == START)
    {
      firstPicked = board.find(position);
      gameData.state = PICKED_FIRST;
      return true;
    }
  if(gameData.state == PICKED_FIRST)
    {
      secondPicked = board.find(position);
      gameData.state = PICKED_SECOND;
      return true;
    }
}

