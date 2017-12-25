#include "stdafx.h"
#include "SampleAI.h"
#include "GameManager.h"

typedef std::vector<Move*> Moves;
Move* SampleAI::makeMove(Board * b, int timeLimit)
{
	Moves* moves = GameManager::getValidMoves(b, this);
	return randomMove(moves);
}

Move* firstLegalMove(Moves* moves) {
	return moves->at(0);
}

Move* randomMove(Moves* moves) {
	return moves->at(std::rand()%moves->size());
}