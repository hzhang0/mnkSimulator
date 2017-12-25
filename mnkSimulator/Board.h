#pragma once
#include "Move.h"
#include <vector>
enum class BoardSpace {
	EMPTY,
	PLAYER1PIECE,
	PLAYER2PIECE
};

typedef std::vector<BoardSpace> row;
typedef std::vector<row*> boardData;

class Board {
private:
	boardData * board;
public:
	Board(int m, int n);
	Board(const Board& board);
	BoardSpace getGrid(int x, int y) const;
	void setGrid(Move* move);
	int getNumRows() const;
	int getNumCols() const;
};
