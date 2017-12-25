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
}
