#pragma once
#include "Board.h"
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
	static std::vector<Move*>* getValidMoves(Board* b, Player* p);
	static bool isValidMove(Board* b, Move* m, Player* p);
}