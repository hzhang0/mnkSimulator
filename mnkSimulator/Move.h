#pragma once
#include "Common.h"
#include <map>

class Player;
class Move {
private:
	int x;
	int y;
	int fromPlayer;

public:
	std::map<int, BoardSpace> playerNumToType = { {1, BoardSpace::PLAYER1PIECE},{2, BoardSpace::PLAYER2PIECE} };
	Move();
	Move(int x, int y, int playerNumber);
	Move(int x, int y, Player* p); // col, row
	int getX() const;
	int getY() const;
	int getPlayer() const;
	bool isWithinBounds(int m, int n) const;
};