#pragma once
#include "Board.h"
#include "Player.h"
#include "GameManager.h"

class AlphaBetaAI : public Player {
private:
	int m;
	int n;
	int k;

public:
	AlphaBetaAI(int m, int n, int k, int timeLimit, int playerNumber);
	virtual Move* makeMove(Board* b, int timeLimit, const Player* otherPlayer) override;
	virtual const char* getName() override;

	int maxScore(Board* b, int alpha, int beta, const Player* otherPlayer);
	int minScore(Board* b, int alpha, int beta, const Player* otherPlayer);
};
