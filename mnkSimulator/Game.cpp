#include "stdafx.h"
#include "Game.h"

Game::Game(int m, int n, int k, Player * p1, Player * p2)
{
	this->m = m;
	this->n = n;
	this->k = k;
	this->player1 = p1;
	this->player2 = p2;
	this->board = new Board(m, n);
}

void Game::startGame()
{
	std::cout << player1->getName() << std::endl;
	std::cout << player2->getName() << std::endl;
}

Game::~Game()
{
	delete player1;
	delete player2;
	delete board;
}
