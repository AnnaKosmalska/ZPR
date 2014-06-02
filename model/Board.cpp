
#include "Board.hpp"
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
  return (playersNumber());
}

int Board::getTile(int x, int y) const
{
  return board.at(std::pair<int, int>(x,y));
}

int Board::choose(int player, int x, int y)
{
  if(gameData.currentPlayer != player)
    return ERR_CURRENT_PLAYER;
  
  if(firstPicked == -1)
    {
      firstPicked = getTile(x, y);
      return firstPicked;
    }
  if(secondPicked == -1)
    {
      secondPicked = getTile(x,y);
      return secondPicked;
    }  
  return ERR_CANNOT_CHOOSE;
}

void Board::removePair()
{
  ///TODO
}

Board::GameData Board::getGameData() const
{
  return gameData;
}

bool Board::initGame(int player, int x, int y)
{
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

int Board::playerReady(int player, int decision)
{
  if(decision == false)
    return -1;
    //TODO deleteplayer
  if(decision == true)
    return 1;
  return 0;
}