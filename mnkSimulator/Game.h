#pragma once
#include "Player.h"
#include "Board.h"
#include "Move.h"
class Game {
private:
	Player * player1;
	Player * player2;
	Board* board;
	int m;
	int n;
	int k;
	int timeLimit;

public:
	Game(int m, int n, int k, int timeLimit, Player* p1, Player* p2);
	void startGame();
	~Game();
};