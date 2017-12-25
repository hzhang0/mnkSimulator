#include "stdafx.h"
#include "Board.h"
#include "GameManager.h"

Board::Board(int m, int n)
{
	//initialize board
	board = new boardData();
	for (int i = 0; i < m; i++) {
		row* r = new row();
		for (int j = 0; j < n; j++) {
			r->push_back(BoardSpace::EMPTY);
		}
		board->push_back(r);
	}
}

Board::Board(const Board & b) //copy constructor
	:Board(b.getNumRows, b.getNumCols)
{
	//deep copy
	for (int i = 0; i < getNumRows(); i++) {
		for (int j = 0; j < getNumCols(); j++) {
			board->at(i)->at(j) = b.getGrid(j, i);
		}
	}
}

BoardSpace Board::getGrid (int x, int y) const
{
	return board->at(y)->at(x);
}

void Board::setGrid(Move* move) //assumes that move will be valid at this point
{
		board->at(move->getY())->at(move->getX()) = (move->playerNumToType)[move->getPlayer()];	
}

int Board::getNumRows() const{
	return board->size();
}

int Board::getNumCols() const{
	return board->at(0)->size();
}