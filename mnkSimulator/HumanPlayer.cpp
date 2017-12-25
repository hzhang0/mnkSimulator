#include "stdafx.h"
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int m, int n, int k, int timeLimit, int playerNumber):
	Player(playerNumber, timeLimit)
{
}

Move* HumanPlayer::makeMove(Board * b, int timeLimit)
{
	return &Move(1,1, this);
}
