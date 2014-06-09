/*! \file Board.cpp
  \brief Plik naglowkowy klasy Board reprezentujacej plansze.
*/

#include "Board.hpp"
#include "Constants.hpp"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>



Board::Board()
{
  winner = 0;
  state = -1;
  currentPlayer = 0;
  firstPicked = -1;
  firstX = -1;
  firstY = -1;
  secondPicked = -1;
  secondX = -1;
  secondY = -1;
  all = -1;
}

Board::~Board()
{
  clearBoard();
  clearPlayers();
}

void Board::clearBoard()
{
  state = -1;
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
  if(state > 0)
    throw GameInProgressException();
  if(state == -1)
    throw GameNotStartedException();
  if(playersNumber() >= MAX_PLAYERS)
    throw MaxPlayersException();
  players.push_back(Player(name, playersNumber()));
  return playersNumber()-1; 
}

int Board::getTile(int x, int y) const
{
  return board.at(std::pair<int, int>(x,y));
}

int Board::choose(int player, int x, int y)
{
  if(player >= playersNumber())
    throw UknownPlayerException();
  if(playersNumber()==0)
    throw NoPlayerException();
  if(player != currentPlayer)
    throw NotCurrentPlayerException();
  if(x>=sizeX || y>=sizeY)
    throw TileOutOfBoardException();
  if(firstPicked != -1 && secondPicked != -1)
    throw TwoTilesChosenException();
  state = 1;
  if(firstPicked == -1)
    {
      firstPicked = getTile(x, y);
      firstX=x;
      firstY=y;
      return firstPicked;
    }
  else
    {
      secondPicked = getTile(x,y);
      secondX=x;
      secondY=y;
      int ret = secondPicked;
      if(firstPicked == secondPicked && firstPicked != -123)
	{
	  players[player].incScore(1);
	  if(players[player].getScore() > winner)
	    winner = players[player].getScore();
	  players[player].addToDeck(firstPicked);
	  removePair();
	}     
      return ret;
    }
}

void Board::removePair()
{
  std::map<std::pair<int, int>, int>::iterator it = board.find(std::pair<int, int>(firstX, firstY));
  if(it != board.end())
    it->second = -123;
  it = board.find(std::pair<int, int>(secondX, secondY));
  if(it != board.end())
    it->second = -123;
  all-=2;
  if(all == 0)
    state = 2;
}

int Board::endTurn()
{
  firstPicked = -1;
  firstX = -1;
  firstY = -1;
  secondPicked = -1;
  secondX = -1;
  secondY = -1;
  int oldCurrent = currentPlayer;
  currentPlayer = nextPlayer();
  while(players[currentPlayer].isDead())
    {
      
      if(currentPlayer == oldCurrent)
	{
	  endGame();
	  break;
	}
      currentPlayer = nextPlayer();
    }
  
  
  return currentPlayer;
}

int Board::nextPlayer()
{
  int next;
  if(currentPlayer == playersNumber()-1) next = 0;
    else next = currentPlayer + 1;
  return next;
}

int Board::initGame(int x, int y)
{
  if(x <= 0 || y <= 0 || (x*y)%2)
    throw WrongParametersException();
  if(state != -1)
    throw GameInProgressException();
  {
    boost::mutex::scoped_lock scoped_lock(initMutex);
    if(state != -1)
      throw GameInProgressException();
    sizeX = x;
    sizeY = y;
    all = sizeY*sizeX;
    firstPicked = -1;
    secondPicked = -1;
    initBoard();
    state = 0;
  }
  return 1;
}

void Board::endGame()
{
  clearPlayers();
  clearBoard();
  state = -1;
  sizeX = 0;
  sizeY = 0;
  currentPlayer = 0;
  firstPicked = -1;
  secondPicked = -1;
  firstX = -1;
  firstY = -1;
  secondX = -1;
  secondY = -1;
  all = -1;
  winner = 0;
}

int Board::playersNumber()
{
  return players.size();
}

void Board::initBoard()
{
  boost::mt19937 gen(static_cast<int>(std::time(0)));  
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

int Board::getWinner(int player)
{
  if(player >= playersNumber())
    throw UknownPlayerException();
  if(playersNumber() == 0)
    throw NoPlayerException();
  if(players[player].getScore() == winner)
    return 1;
  return 0;

int Board::getScore(int player)
{
  if(player >= playersNumber())
    throw UknownPlayerException();
  if(playersNumber()==0)
    throw NoPlayerException();
  return players[player].getScore();
}
std::string Board::getName(int player)
{
  if(player >= playersNumber())
    throw UknownPlayerException();
  if(playersNumber()==0)
    throw NoPlayerException();
  return players[player].getName();
}

int Board::playerDead(int player)
{
  if(player >= playersNumber())
    throw UknownPlayerException();
  if(playersNumber()==0)
    throw NoPlayerException();
  players[player].playerDead();
  if(player == currentPlayer)
    endTurn();
  return currentPlayer;
}


