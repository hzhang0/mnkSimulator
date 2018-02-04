#include "stdafx.h"
#include "AlphaBetaAI.h"
#include "GameManager.h"

AlphaBetaAI::AlphaBetaAI(int m, int n, int k, int timeLimit, int playerNumber) :
	Player(playerNumber, timeLimit), m(m), n(n), k(k)
{

}

int AlphaBetaAI::minScore(const Board& b, int alpha, int beta, const Player* otherPlayer) {
	if (GameManager::isTerminal(b) != EndState::NOT_TERMINAL) {
		return GameManager::getScore(b, this);		
	}
	Moves moves{ GameManager::getValidMoves(b, otherPlayer) };
	for (int i = 0; i < moves.size(); i++)
	{
		Move move = moves.at(i);
		Board newBoard = GameManager::simulateMove(b, move, otherPlayer);
		beta = maxScore(newBoard, alpha, beta, otherPlayer);
		if (beta <= alpha) {
			return alpha;
		}
	}
	return beta;
}
int AlphaBetaAI::maxScore(const Board& b, int alpha, int beta, const Player* otherPlayer) {
	if (GameManager::isTerminal(b) != EndState::NOT_TERMINAL) {
		return GameManager::getScore(b, this);
	}
	Moves moves{ GameManager::getValidMoves(b, this) };
	for (int i = 0; i < moves.size(); i++)
	{
		Move move = moves.at(i);
		Board newBoard = GameManager::simulateMove(b, move, this);
		int minval = minScore(newBoard, alpha, beta, otherPlayer);
		alpha = alpha > minval ? alpha : minval;
		if (alpha >= beta) {
			return beta;
		}
	}
	return alpha;
}

Move AlphaBetaAI::makeMove(Board b, int timeLimit, const Player* otherPlayer, std::atomic<bool>* timesUp)
{
	startTime = Clock::now();
	Moves moves = GameManager::getValidMoves(b, this);
	Move move{ moves.at(0) };
	int score = 0;
	for (int i = 0; i < moves.size(); i++)
	{
		Board newBoard = GameManager::simulateMove(b, moves.at(i), this);
		int result = minScore(newBoard, 0, 100, otherPlayer);
		if (result == 100) {
			return moves.at(i);
		}
		if (result > score) {
			score = result;
			move = moves.at(i);
		}
		if (*timesUp) {
			//std::cout << "Timed out!" << std::endl;
			return move;
		}
	}
	return move;
}

const char * AlphaBetaAI::getName()
{
	return "AlphaBetaAI";
}

