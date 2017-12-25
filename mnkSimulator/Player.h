#pragma once
#include "Move.h"
#include "Board.h"
enum class PlayerType {
	HUMAN,
	SAMPLEAI
};
class Player {
protected:
	PlayerType playerType;
	int playerNumber;

public:
	virtual Move makeMove(Board* b, int timeLimit) = 0;
	PlayerType getPlayerType();
	int getPlayerNumber();
};