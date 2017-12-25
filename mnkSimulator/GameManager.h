#pragma once
#include "Board.h"

typedef std::vector<Move*> Moves;
enum class EndState {
	NOT_TERMINAL,
	YOU_WIN,
	YOU_LOSE,
	DRAW
};

namespace GameManager {
	static EndState isTerminal(Board* b);
	static EndState isTerminal(Board* b, Move* lastMove);
	static Board simulateMove(Board* b, Move* m, Player* p);
	static Moves* getValidMoves(Board* b, Player* p);
	static bool isValidMove(Board* b, Move* m, Player* p);
}