
#include "Board.hpp"
#include "Constants.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

Board::Board()
{
  //sizeX=1;
  //sizeY=1;
  //initBoard();
  state = 0;
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

int Board::addPlayer(std::string name)
{
  if(playersNumber() >= MAX_PLAYERS)
    return -1;
  players.push_back(Player(name, playersNumber()));
  return playersNumber()-1;
}

int Board::getTile(int x, int y) const
{
  return board.at(std::pair<int, int>(x,y));
}

int Board::choose(int player, int x, int y)
{
  if(playersNumber()==0)
    return -300;
  if(player != currentPlayer)
    return -200;
  if(x>=sizeX || y>=sizeY)
    return -100;
  if(firstPicked == -1)
    {
      secondPicked = -1;
      firstPicked = getTile(x, y);
      return firstPicked;
    }
  if(secondPicked == -1)
    {
      secondPicked = getTile(x,y);
      if(firstPicked == secondPicked)
	players[player].incScore(1);
      firstPicked = -1;
      if(currentPlayer == playersNumber()-1) currentPlayer = 0;
      else ++currentPlayer;
      return secondPicked;
    }
  return -1;
}

void Board::removePair()
{
  ///TODO
}



void Board::initGame(int x, int y)
{
  sizeX = x;
  sizeY = y;
  firstPicked = -1;
  secondPicked = -1;
  initBoard();
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
  boost::mt19937 gen;
  

  
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
	  boost::uniform_int<> dist(0, fullSize-1);
	  boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);
	  int pickedIndex = die();
	  std::pair<int,int> position;
	  position = std::make_pair(i, j);
	  board.insert(std::pair<std::pair<int,int>, int>(position, tiles[pickedIndex]));
	  //board.insert(std::pair<std::pair<int,int>, int>(position, tiles[i*sizeX+j]));
	  tiles[pickedIndex] = tiles[--fullSize];
	}
    }
}

bool Board::checkPair(int player)
{
  if(state == PICKED_SECOND)
    {
      state = END;
      if(firstPicked == secondPicked)
	return true;
    }
  return false;
}



