#pragma once
#include "Common.h"
#include "Board.h"
#include "Move.h"
#include <chrono>
#include <atomic>
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::time_point<std::chrono::steady_clock> Time;

class Player {
protected:
	PlayerType playerType;
	int playerNumber;
	Time startTime;
	int timeLimit;
	int getTimeLeft();
	const Player* otherPlayer;
	Player(int playerNumber, int timeLimit);

public:	
	virtual Move makeMove(Board b, int timeLimit, const Player* otherPlayer, std::atomic<bool>* timesUp) = 0;
	virtual const char* getName() = 0;
	PlayerType getPlayerType();
	int getPlayerNumber() const;
	virtual ~Player();
};