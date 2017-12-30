#pragma once
#include "Move.h"
#include <iostream>
#include <vector>
#include <map>
#include "Common.h"

typedef std::vector<BoardSpace> row;
typedef std::vector<row*> boardData;

class Board {
private:
	boardData * board;
	int k;
public:	
	Board(int m, int n, int k);
	Board(const Board& board);
	BoardSpace getGrid(int x, int y) const;
	void setGrid(Move* move);
	int getNumRows() const;
	int getNumCols() const;
	int getK() const;
	friend std::ostream& operator<< (std::ostream &out, Board& b);
	~Board();
};
