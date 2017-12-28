#include "stdafx.h"
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int m, int n, int k, int timeLimit, int playerNumber):
	Player(playerNumber, timeLimit)
{
}

Move* HumanPlayer::makeMove(Board * b, int timeLimit)
{	
	return new Move(1,1, getPlayerNumber());
}

const char * HumanPlayer::getName()
{
	return "Human";
}
