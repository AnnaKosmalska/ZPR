
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
  players.push_back(Player(name, playersNumber()));
  return true;
}

unsigned Board::getTile(Position position)
{
  return board[position];
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
  if(gameData.state == PICKED_SECOND || gameData.state == END)
    {
      return false;
    }
}

void Board::removePair(PairOnBoard pairToRemove)
{
  board.erase(pairToRemove.first);
  board.erase(pairToRemove.second);
}

static &Board Board::getInstance()
{
  static Board instance;
  return instance;
}

void Board::startGame()
{
  initBoard(size);
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

void initBoard(int sizeOfBoard)
{
  Tile newTile;
  for(unsigned i = 0; i < size; i++)
    {
      for(unsigned j = 0; j < size; j++)
	{
	  newTile = randomTile();
	  board.insert(std::pair<position, unsigned>(std::pair<unsigned, unsigned>(i, j)));
	}
    }
}

void Board::randomTile()
{
  //tu trzeba losować z talii kolejną kartę, najlepiej chyba z listy, bo łatwo przepiąć wskaźniki
}
