#include <Game.hpp>

static Game& Game::getInstance()
{
  static Game instance;
  return instance;
}
