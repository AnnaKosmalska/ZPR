
#include "Player.hpp"

Player::Player(std::string _name, int _ID)
{
  name = _name;
  ID = _ID;
  score = 0;
}

Player::~Player()
{
  delete deck;
}

void Player::incScore(int points)
{
  score += points;
}

void Player::addToDeck(int newTile)
{
  deck->addTile(newTile);
}

std::string Player::getName() const
{
  return name;
}

int Player::getID() const
{
  return ID;
}

Deck* Player::getDeck() const
{
  return deck;
}

int Player::getScore() const
{
  return score;
}

