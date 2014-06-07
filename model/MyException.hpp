

#ifndef MYEXCEPTION
#define MYEXCEPTION

#include <exception>

class BaseException: public std::exception
{
};

class GameInProgressException: public BaseException
{
};

class MaxPlayersException: public BaseException
{
};

class UknownPlayerException: public BaseException
{
};

class NoPlayerException: public BaseException
{
};

class NotCurrentPlayerException: public BaseException
{
};

class TileOutOfBoardException: public BaseException
{
};

class TwoTilesChosenException: public BaseException
{
};

class GameNotStartedException: public BaseException
{
};

class WrongParametersException: public BaseException
{
};

#endif
