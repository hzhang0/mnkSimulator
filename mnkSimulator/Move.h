#pragma once
#include "Player.h"
#include <map>
class Move {
private:
	int x;
	int y;
	int fromPlayer;

public:
	std::map<int, BoardSpace> playerNumToType = { {1, BoardSpace::PLAYER1PIECE},{2, BoardSpace::PLAYER2PIECE} };
	Move(int x, int y, int playerNumber);
	Move(int x, int y, Player* player);
	int getX();
	int getY();
	int getPlayer();
	bool isWithinBounds(int m, int n);
};