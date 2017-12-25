#pragma once
#include "Player.h"
#include "Board.h"
#include "Move.h"
class Game {
private:
	Player * player1;
	Player * player2;
	Board* board;

public:
	Game(int m, int n, int k, Player* p1, Player* p2);
	void startGame();
};