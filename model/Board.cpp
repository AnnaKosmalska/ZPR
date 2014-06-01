
#include "Board.hpp"
#include "Constants.hpp"
#include <boost/random.hpp>

Board::Board()
{
  sizeX = 5;
  sizeY = 5;
  gameData.state = 0;
  gameData.currentPlayer = 0;
}

Board::~Board()
{
  clearBoard();
  clearPlayers();
}

void Board::clearBoard()
{
  gameData.state = 0;
  gameData.currentPlayer = 0;
  board.clear();
}

void Board::clearPlayers()
{
  gameData.currentPlayer = 0;
  players.clear();
}

int Board::addPlayer(std::string name)
{
  if(playersNumber() >= MAX_PLAYERS)
    return ERR_MAX_PLAYERS;
  players.push_back(Player(name, playersNumber()));
  return (playersNumber()-1);
}

int Board::getTile(int x, int y) const
{
  return board.at(std::pair<int, int>(x,y));
}

bool Board::choose(int player, int x, int y)
{
  gameData.currentPlayer = player;
  if(gameData.state == START)
    {
      firstPicked = board[std::pair<int, int>(x,y)];
      gameData.state = PICKED_FIRST;
      return true;
    }
  if(gameData.state == PICKED_FIRST)
    {
      secondPicked = board[std::pair<int, int>(x,y)];
      gameData.state = PICKED_SECOND;
      return true;
    }
  if(gameData.state == PICKED_SECOND || gameData.state == END)
    {
      return false;
    }
  return false;
}

void Board::removePair()
{
  ///TODO
}



void Board::startGame(int x, int y)
{
  if((x*y)%2)
    ++x;
  sizeX = x;
  sizeY = y;
  initBoard();
}

void Board::endGame()
{
  clearPlayers();
  clearBoard();
  gameData.state = 3;
  gameData.currentPlayer = 0;
}

int Board::playersNumber()
{
  return players.size();
}

void Board::initBoard()
{
  
  std::vector<int> tiles;
  int fullSize = sizeX*sizeY;
  for(int i = 0; i < fullSize; i+=2)
    {
      tiles.push_back(i);
      tiles.push_back(i);
    }
  
  for(int i = 0; i < sizeX; ++i)
    {
      for(int j = 0; j < sizeY; ++j)
	{
	  int pickedIndex = randomTile(fullSize);
	  std::pair<int,int> position;
	  position = std::make_pair(i, j);
	  board.insert(std::pair<std::pair<int,int>, int>(position, tiles[pickedIndex]));
	  tiles[pickedIndex] = tiles[fullSize];
	  --fullSize;	  
	}
    }
}

int Board::randomTile(int range)
{
  /* boost::mt19937 generator(static_cast<int>(std::time(0)));
  boost::random::uniform_int_distribution<> distance(0, range-1);
  return randRange(randTileGen);*/
  return 1;
}

bool Board::checkPair(int player)
{
  if(gameData.state == PICKED_SECOND)
    {
      gameData.state = END;
      if(firstPicked == secondPicked)
	return true;
    }
  return false;
}



