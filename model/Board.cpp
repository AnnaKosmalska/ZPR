
#include "Board.hpp"
#include <boost/random.hpp>

Board::Board()
{
  sizeX = 5;
  sizeY = 5;
  initBoard();
  state = 0;
  firstPicked = -1;
  secondPicked = -1;
  currentPlayer = 0;
}

Board::~Board()
{
  clearBoard();
  clearPlayers();
}

void Board::clearBoard()
{
  state = 0;
  currentPlayer = 0;
  board.clear();
}

void Board::clearPlayers()
{
  currentPlayer = 0;
  players.clear();
}

int Board::addPlayer()
{
  if(playersNumber() >= MAX_PLAYERS)
    return ERR_MAX_PLAYERS;
  std::string newName = "Ania";
  players.push_back(Player(newName, playersNumber()));
  return playersNumber();
}

int Board::getTile(int x, int y) const
{
  return board.at(std::pair<int, int>(x,y));
}

int Board::choose(int player, int x, int y)
{
  /*if(currentPlayer != player-1)
    return ERR_CURRENT_PLAYER;*/
  
  if(firstPicked == -1)
    {
      firstPicked = getTile(x, y);
      return firstPicked;
    }
  if(secondPicked == -1)
    {
      secondPicked = getTile(x,y);
      
      if(secondPicked == firstPicked)
	players[currentPlayer].incScore(1);
      firstPicked = -1;
      int ret = secondPicked;
      secondPicked = -1;
      currentPlayer = nextPlayer();
      return ret;
    }  
  return ERR_CANNOT_CHOOSE;
}

int Board::nextPlayer()
{
  int ret =  currentPlayer+1;
  if(ret > playersNumber())
    ret = 0;
  return ret;
}

void Board::removePair()
{
  ///TODO
}


bool Board::initGame(int player, int x, int y)
{
  if(player != 1)
    return false;
  if((x*y)%2)
    ++x;
  sizeX = x;
  sizeY = y;
  initBoard();
  return 1;
}

void Board::endGame()
{
  clearPlayers();
  clearBoard();
  state = 3;
  currentPlayer = 0;
}

int Board::playersNumber()
{
  return players.size();
}

void Board::initBoard()
{
  
  std::vector<int> tiles;
  int fullSize = sizeX*sizeY/2;
  for(int i = 0; i < fullSize; ++i)
    {
      tiles.push_back(i);
      tiles.push_back(i);
    }
  fullSize*=2;
  for(int i = 0; i < sizeX; ++i)
    {
      for(int j = 0; j < sizeY; ++j)
	{
	  int pickedIndex = randomTile(fullSize);
	  std::pair<int,int> position;
	  position = std::make_pair(i, j);
	  board.insert(std::pair<std::pair<int,int>, int>(position, tiles[pickedIndex]));
	  tiles[pickedIndex] = tiles[--fullSize];	  
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

int Board::playerReady(int player, int decision)
{
  if(decision == false)
    return -1;
    //TODO deleteplayer
  if(decision == true)
    return 1;
  return 0;
}
