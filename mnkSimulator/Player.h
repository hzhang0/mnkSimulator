#pragma once
#include "Move.h"
#include "Board.h"
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::steady_clock> time;

enum class PlayerType {
	HUMAN,
	SAMPLEAI
};
class Player {
protected:
	PlayerType playerType;
	int playerNumber;
	time startTime;
	int timeLimit;
	int getTimeLeft();
	Player(int playerNumber, int timeLimit);

public:	
	virtual Move* makeMove(Board* b, int timeLimit) = 0;
	PlayerType getPlayerType();
	int getPlayerNumber();	
};