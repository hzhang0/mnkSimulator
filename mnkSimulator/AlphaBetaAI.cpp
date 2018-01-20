#include "stdafx.h"
#include "AlphaBetaAI.h"
#include "GameManager.h"

AlphaBetaAI::AlphaBetaAI(int m, int n, int k, int timeLimit, int playerNumber) :
	Player(playerNumber, timeLimit), m(m), n(n), k(k)
{

}

int AlphaBetaAI::minScore() {
	return 0;
}
int AlphaBetaAI::maxScore() {
	return 1;
}

Move* AlphaBetaAI::makeMove(Board * b, int timeLimit)
{
	startTime = Clock::now();
	Moves* moves = GameManager::getValidMoves(b, this);
	return moves->at(std::rand() % moves->size());
}

const char * AlphaBetaAI::getName()
{
	return "AlphaBetaAI";
}

