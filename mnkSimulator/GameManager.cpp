#include "stdafx.h"
#include "GameManager.h"

EndState GameManager::isTerminal(Board* b)
{
	return EndState();
}

EndState GameManager::isTerminal(Board* b, Move* lastMove)
{
	return EndState();
}

Board GameManager::simulateMove(Board* b, Move* m, Player* p)
{
	return Board();
}

Board GameManager::getValidMoves(Board* b, Player* p)
{
	return Board();
}
