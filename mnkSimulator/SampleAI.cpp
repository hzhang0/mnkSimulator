#include "stdafx.h"
#include "SampleAI.h"
#include "GameManager.h"

SampleAI::SampleAI(int m, int n, int k, int timeLimit, int playerNumber):
	Player(playerNumber, timeLimit), m(m), n(n), k(k)
{

}

Move SampleAI::firstLegalMove(Moves& moves) {
	return moves.at(0);
}

Move SampleAI::randomMove(Moves& moves) {
	return moves.at(std::rand() % moves.size());
}

Move SampleAI::makeMove(Board b, int timeLimit, const Player* otherPlayer)
{
	startTime = Clock::now();
	Moves moves{ GameManager::getValidMoves(b, this) };
	return randomMove(moves);
}

const char * SampleAI::getName()
{
	return "SampleAI";
}

