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

int Player::getPlayerNumber()
{
	return playerNumber;
}

int Player::getTimeLeft()
{
	return timeLimit - std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - startTime).count();
}
