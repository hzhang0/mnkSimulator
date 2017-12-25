#pragma once
#include "Board.h"

class SampleAI : public Player {
	SampleAI(int m, int n, int k, int timeLimit);
	virtual Move makeMove(Board* b, int timeLimit) override;
};