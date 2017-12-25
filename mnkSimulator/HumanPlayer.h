#pragma once
#include "Board.h"

class HumanPlayer : public Player {
	HumanPlayer(int m, int n, int k, int timeLimit);
	virtual Move makeMove (Board* b, int timeLimit) override;	
};