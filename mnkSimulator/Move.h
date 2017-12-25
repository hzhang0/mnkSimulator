#pragma once
#include "Player.h"
class Move {
private:
	int x;
	int y;
	int fromPlayer;

public:
	Move(int x, int y, int playerNumber);
	Move(int x, int y, Player* player);
	int getX();
	int getY();
	bool isWithinBounds(int m, int n);
};