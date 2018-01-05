#pragma once
#include "Board.h"
#include "Player.h"
typedef std::vector<Move*> Moves;
enum class EndState {
	NOT_TERMINAL,
	PLAYER1_WINS,
	PLAYER2_WINS,
	DRAW
};
enum class ConnectionDirection{
	LEFTDIAG,
	RIGHTDIAG,
	VERTICAL,
	HORIZONTAL
};

namespace GameManager {
	EndState isTerminal(Board* b);
	EndState isTerminal(Board* b, Move* lastMove);
	int addConnectionToBoard(std::vector<std::vector<int>*> * b, int x, int y, ConnectionDirection c);
	Board* simulateMove(Board* b, Move* m, Player* p);
	Moves* getValidMoves(Board* b, Player* p);
	bool isValidMove(Board* b, Move* m, Player* p);
};
