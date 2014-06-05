

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

#endif
