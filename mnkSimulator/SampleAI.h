#pragma once
#include "Board.h"
#include "Player.h"
#include "GameManager.h"

class SampleAI : public Player {
private:
	int m;
	int n;
	int k;

public:
	SampleAI(int m, int n, int k, int timeLimit, int playerNumber);
	virtual Move makeMove(Board b, int timeLimit, const Player* otherPlayer) override;
	Move firstLegalMove(Moves& moves);
	Move randomMove(Moves& moves);
	virtual const char* getName() override;
};