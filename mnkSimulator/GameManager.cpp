#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"

EndState GameManager::isTerminal(Board* b)
{
	std::vector<std::vector<int>*> * p1 = new std::vector<std::vector<int>*>();
	std::vector<std::vector<int>*> * p2 = new std::vector<std::vector<int>*>();
	int width = b->getNumCols();
	int height = b->getNumRows();
	p1->reserve(height);
	p2->reserve(height);
	int k = b->getK();
	bool hasEmpty{false};
	int connection = 0;
	std::vector<ConnectionDirection> dir = {
		ConnectionDirection::LEFTDIAG,
		ConnectionDirection::RIGHTDIAG,
		ConnectionDirection::VERTICAL,
		ConnectionDirection::HORIZONTAL
	};

	for (int c = 0; c < dir.size(); c++){ // Loop through all directions of connections
		p1 = new std::vector<std::vector<int>*>();
		p2 = new std::vector<std::vector<int>*>();

		for (int i = 0; i < height; i++) {
			std::vector<int>* row = new std::vector<int>();
			row->reserve(width);
			for (int j = 0; j < width; j++) { row->push_back(0); }
			p1->push_back(row);
			p2->push_back(row);
			for (int j = 0; j < width; j++) {
				switch(b->getGrid(j,i)) {
				    case BoardSpace::EMPTY:
						hasEmpty = true;
						break;

				    case BoardSpace::PLAYER1PIECE:
						connection = addConnectionToBoard(p1, j, i, dir.at(c));
						if(connection >= k){return EndState::PLAYER1_WINS;} // Player 1 wins
						break;

					case BoardSpace::PLAYER2PIECE:
						connection = addConnectionToBoard(p2, j, i, dir.at(c));
						if(connection >= k){return EndState::PLAYER2_WINS;} // Player 2 wins
						break;
				}
			}
		}
	}
	if(!hasEmpty) return EndState::DRAW; // If board is full (not empty) and nobody wins, draw.
	return EndState::NOT_TERMINAL; // Not yet terminal
}

EndState GameManager::isTerminal(Board* b, Move* lastMove) //faster method if last move is provided
{
	return EndState();
}

int GameManager::addConnectionToBoard(std::vector<std::vector<int>*> * b, int x, int y, ConnectionDirection c){
	int h = b->size();
	int w = b->at(0)->size();
	switch(c){
		case ConnectionDirection::LEFTDIAG:
			if(x > 0 && y > 0){ b->at(y)->at(x) = b->at(y-1)->at(x-1) + 1; }
			else{ b->at(y)->at(x) = 1; }
			break;
		case ConnectionDirection::RIGHTDIAG:
			if(x != w-1 && y != h-1){ b->at(y)->at(x) = b->at(y+1)->at(x+1) + 1; }
			else{ b->at(y)->at(x) = 1; }
			break;
		case ConnectionDirection::VERTICAL:
			if(y != 0){ b->at(y)->at(x) = b->at(y-1)->at(x) + 1; }
			else{ b->at(y)->at(x) = 1; }
			break;
		case ConnectionDirection::HORIZONTAL:
			if(x != 0){ b->at(y)->at(x) = b->at(y)->at(x-1) + 1; }
			else{ b->at(y)->at(x) = 1; }
			break;
	}
	return b->at(y)->at(x);
}

Board* GameManager::simulateMove(Board* b, Move* m, Player* p)
{
	//check for terminality first. If b is a terminal state, raise an error.
	//Also raise error if not valid move.
	//returns copy of board (use copy constructor)

	if (isTerminal(b) != EndState::NOT_TERMINAL || !isValidMove(b, m, p)) {
		throw std::bad_exception();
		return nullptr;
	}

	b->setGrid(m);

	return new Board(*b);
}

Moves* GameManager::getValidMoves(Board* b, Player* p)
{
	//check for terminality first. If terminal, return empty list.
	Moves * m = new Moves();

	if (isTerminal(b) != EndState::NOT_TERMINAL) {
		return m;
	}

	for (int i = 0; i < b->getNumRows(); i++)
	{
		for (int j = 0; j < b->getNumCols(); j++)
		{
			if (b->getGrid(j, i) == BoardSpace::EMPTY) {
				m->push_back(new Move(j, i, p->getPlayerNumber()));
			}
		}
	}
	return m;
}

bool GameManager::isValidMove(Board * b, Move * m, Player * p)
{
	//No need to check for terminality here. Will be done inside game loop.
	//check m->isWithinBounds() first
	//also check if m->getPlayer() == p->getPlayerNumber()

	if (!m->isWithinBounds(b->getNumCols(), b->getNumRows())) return false;

	if (m->getPlayer() != p->getPlayerNumber()) return false;

	if (b->getGrid(m->getX(), m->getY()) == BoardSpace::EMPTY) {
		return true;
	}

	return false;
}
