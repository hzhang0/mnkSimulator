#include "stdafx.h"
#include "Player.h"
#include "Move.h"

Move::Move() {}

Move::Move(int x, int y, int playerNumber):
	x(x), y(y), fromPlayer(playerNumber)
{	
}

Move::Move(int x, int y, Player* p) :
	x(x), y(y), fromPlayer(p->getPlayerNumber())
{
}


int Move::getX() const
{
	return x;
}

int Move::getY() const
{
	return y;
}

bool Move::isWithinBounds(int m, int n) const
{
	return (y<m && y>=0 && x<n && x>=0);
}

int Move::getPlayer() const {
	return fromPlayer;
}