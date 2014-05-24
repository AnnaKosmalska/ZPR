
#include "Player.hpp"

Player::Player(string name, int ID)
{
  this.name = name;
  this.ID = ID;
  this. score = 0;
}

Player::~Player()
{
  delete deck;
}

void Player::incScore(int points)
{
  score += points;
}

void Player::addToDeck(Tile* pair)
{
  deck.addTile(pair);
}

string Player::getName()
{
  return name;
}

int Player::getID()
{
  return ID;
}

Deck* Player::getDeck()
{
  return deck;
}

int Player::getScore(){
  return score;
}
