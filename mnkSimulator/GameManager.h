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
	EndState isTerminal(const Board* b);
	EndState isTerminal(const Board* b, Move* lastMove);
	int isTerminalRecursive(const Board* b, BoardSpace s, int x, int y, int dx, int dy);
	int addConnectionToBoard(std::vector<std::vector<int>*> * b, int x, int y, ConnectionDirection c);
	Board* simulateMove(const Board* b, const Move* m, const Player* p);
	Moves* getValidMoves(const Board* b, const Player* p);
	int getScore(const Board* b, const Player* p);
	bool isValidMove(const Board* b, const Move* m, const Player* p);
};
