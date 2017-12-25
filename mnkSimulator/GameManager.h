#pragma once
#include "Board.h"
#include "Player.h"
typedef std::vector<Move*> Moves;
enum class EndState {
	NOT_TERMINAL,
	YOU_WIN,
	YOU_LOSE,
	DRAW
};

namespace GameManager {
	EndState isTerminal(Board* b);
	EndState isTerminal(Board* b, Move* lastMove);
	Board* simulateMove(Board* b, Move* m, Player* p);
	Moves* getValidMoves(Board* b, Player* p);
	bool isValidMove(Board* b, Move* m, Player* p);
};