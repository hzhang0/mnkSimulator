#include "stdafx.h"
#include "AlphaBetaAI.h"
#include "GameManager.h"

AlphaBetaAI::AlphaBetaAI(int m, int n, int k, int timeLimit, int playerNumber) :
	Player(playerNumber, timeLimit), m(m), n(n), k(k)
{

}

int AlphaBetaAI::minScore(Move* m, Board* b, int alpha, int beta) {
	Moves* moves = GameManager::getValidMoves(b, getOpponent());
	for (int i = 0; i < moves->size(); i++)
	{
		Move* move = moves->at(i);
		Move* myMove = m;
		Move* opMove = move;
		Board* newBoard = GameManager::simulateMove(b, opMove, getOpponent());
		beta = maxScore(newBoard, alpha, beta);	
		if (beta <= alpha) {
			return alpha;
		}
	}
	return beta;
}
int AlphaBetaAI::maxScore(Board* b, int alpha, int beta) {
	if (GameManager::isTerminal(b) != EndState::NOT_TERMINAL) {
		return GameManager::getScore(b, this);
	}
	Moves* moves = GameManager::getValidMoves(b, getOpponent());
	for (int i = 0; i < moves->size(); i++)
	{
		int minval = minScore(moves->at(i), b, alpha, beta);
		alpha = alpha > minval ? alpha : minval;
		if (alpha >= beta) {
			return beta;
		}
	}
	return alpha;
}
Player* AlphaBetaAI::getOpponent() {
	for (int i = 0; i < GameManager::Players->size(); i++)
	{
		if (this->getPlayerNumber() != GameManager::Players->at(i)->getPlayerNumber()) {
			return GameManager::Players->at(i);
		}
	}
	return nullptr;
}
int AlphaBetaAI::getOrder(Player* p) {
	for (int i = 0; i < GameManager::Players->size(); i++)
	{
		if (p->getPlayerNumber() == GameManager::Players->at(i)->getPlayerNumber()) {
			return i;
		}
	}
	return -1;
}

Move* AlphaBetaAI::makeMove(Board * b, int timeLimit)
{
	startTime = Clock::now();
	Moves* moves = GameManager::getValidMoves(b, this);
	Move* move = moves->at(0);
	int score = 0;
	for (int i = 0; i < moves->size(); i++)
	{
		int result = minScore(moves->at(i), b, 0, 100);
		if (result == 100) {
			return moves->at(i);
		}
		if (result > score) {
			score = result;
			move = moves->at(i);
		}
	}
	return move;
}

const char * AlphaBetaAI::getName()
{
	return "AlphaBetaAI";
}

