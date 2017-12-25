#pragma once
#include "Board.h"

class HumanPlayer : public Player {
private:

public:
	HumanPlayer(int m, int n, int k, int timeLimit, int playerNumber);
	virtual Move* makeMove (Board* b, int timeLimit) override;	
};