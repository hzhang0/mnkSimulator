#include "stdafx.h"
#include "Player.h"
#include "Move.h"

Player::Player(int playerNumber, int timeLimit)
	:playerNumber(playerNumber), timeLimit(timeLimit)
{	
}

PlayerType Player::getPlayerType()
{
	return PlayerType();
}

int Player::getPlayerNumber() const
{
	return playerNumber;
}

Player::~Player()
{
}

int Player::getTimeLeft()
{
	return static_cast<int>(timeLimit - std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - startTime).count());
}
