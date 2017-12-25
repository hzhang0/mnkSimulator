#pragma once
#include "Move.h"
#include <vector>
enum class BoardSpace {
	EMPTY,
	PLAYER1PIECE,
	PLAYER2PIECE
};

typedef std::vector<std::vector <BoardSpace>*> boardData;

class Board {
private:
	boardData * board;
public:
	Board(int m, int n);
	Board(const Board& board);
	BoardSpace getGrid(int x, int y);
	void setGrid(Move* move);
};
