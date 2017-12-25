#include "stdafx.h"
#include "GameManager.h"

EndState GameManager::isTerminal(Board* b)
{
	return EndState();
}

EndState GameManager::isTerminal(Board* b, Move* lastMove) //faster method if last move is provided
{
	return EndState();
}

Board GameManager::simulateMove(Board* b, Move* m, Player* p)
{
	//check for terminality first. If b is a terminal state, raise an error.
	//Also raise error if not valid move.
	return Board();
}

Moves* GameManager::getValidMoves(Board* b, Player* p)
{
	//check for terminality first. If terminal, return empty list.
	return Board();
}

bool GameManager::isValidMove(Board * b, Move * m, Player * p)
{
	//No need to check for terminality here. Will be done inside game loop.
	//check m->isWithinBounds() first
	return false;
}
