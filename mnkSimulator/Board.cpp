#include "stdafx.h"
#include "Board.h"
#include "GameManager.h"

Board::Board(int m, int n, int k):
	k(k)
{
	//initialize board
	for (int i = 0; i < m; i++) {
		row r{};
		for (int j = 0; j < n; j++) {
			r.push_back(BoardSpace::EMPTY);
		}
		board.push_back(r);
	}
}

Board::Board(const Board & b): k(b.getK()) //copy constructor
{
	//deep copy
	for (int i = 0; i < b.getNumRows(); i++) {
		row r{};
		for (int j = 0; j < b.getNumCols(); j++) {
			r.push_back(b.getGrid(j, i));
		}
		board.push_back(r);
	}
}

BoardSpace Board::getGrid (int x, int y) const
{
	return board.at(y).at(x);
}

bool Board::isWithinBounds(int x, int y) const {
	return (y >= 0 && y < board.size() && x >= 0 && x < board.at(0).size());
}

void Board::setGrid(const Move& move) //assumes that move will be valid at this point
{
		board.at(move.getY()).at(move.getX()) = (move.playerNumToType).at(move.getPlayer());	
}

int Board::getNumRows() const{
	return static_cast<int>(board.size());
}

int Board::getNumCols() const{
	return static_cast<int>(board.at(0).size());
}

int Board::getK() const
{
	return k;
}

Board::~Board()
{
}

void fillSpace(std::ostream& out, int i) {
	if (i < 10) {
		out << ' ';
	}
}

void fillSpace2(std::ostream& out, int i) {
	if (i >= 10) {
		out << ' ';
	}
}

std::ostream& operator<<(std::ostream & out, Board & b)
{
	out << "   ";
	for (int i = 0; i < b.getNumCols(); i++) {
		out << i << ' ';
	}
	out << std::endl;
	for (int i = 0; i < b.getNumRows(); i++) {
		out << i << ' ';
		fillSpace(out, i);
		for (int j = 0; j < b.getNumCols(); j++) {
			out << BoardSpaceToChar.at(b.getGrid(j, i)) << ' ';
			fillSpace2(out, j);
		}
		out << std::endl;
	}
	return out;
}
