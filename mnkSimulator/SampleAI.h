#pragma once
#include "Board.h"

class SampleAI : public Player {
private:
	int m;
	int n;
	int k;

public:
	SampleAI(int m, int n, int k, int timeLimit, int playerNumber);
	virtual Move* makeMove(Board* b, int timeLimit) override;
};