#include "stdafx.h"
#include "Game.h"
#include "Common.h"
#include "GameManager.h"
#include <chrono>
#include <thread>
#include <future>
#include <Windows.h>

Game::Game(int m, int n, int k, int timeLimit, Player * p1, Player * p2)
{
	this->m = m;
	this->n = n;
	this->k = k;
	this->player1 = p1;
	this->player2 = p2;
	this->board = new Board(m, n, k);
}

void clearScreen() {
	if (system("CLS")) system("clear");
}

template<class T>
void swap(T*& a, T*& b) {
	T* temp = a;
	a = b;
	b = temp;
}

void timer() {
	for (int i = 0; i<10; ++i)
	{
		std::cout << (10 - i) << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void Game::startGame()
{
	clearScreen();
	std::cout << "Player 1: " << player1->getName() << std::endl;
	std::cout << "Player 2: " << player2->getName() << std::endl;
	std::cout << "Starting game..." << std::endl;
	auto curPlayer = player1;
	auto otherPlayer = player2;
	EndState es = GameManager::isTerminal(board);
	int move{ 1 };
	while (es == EndState::NOT_TERMINAL) {
		std::cout << "Move " << move << std::endl;
		std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", to move." << std::endl << std::endl;
		std::cout << *board;

		auto future = std::async(timer);
		
		POINT p;
		GetCursorPos(&p);
		std::cout << p.x << std::endl;		
		std::cout << p.y << std::endl;
		break;
		es = GameManager::isTerminal(board);
		clearScreen();
		if (es != EndState::NOT_TERMINAL) {
			swap(curPlayer, otherPlayer);
		}
	}

	switch (es) {
		case EndState::DRAW:
			std::cout << "The game ends in a draw." << std::endl;
			break;
		case EndState::YOU_LOSE:
			std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", loses." << std::endl;
			std::cout << "Player " << otherPlayer->getPlayerNumber() << ", " << otherPlayer->getName() << ", wins." << std::endl;
			break;
		case EndState::YOU_WIN:
			std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", wins." << std::endl;
			std::cout << "Player " << otherPlayer->getPlayerNumber() << ", " << otherPlayer->getName() << ", loses." << std::endl;
			break;
	}
	std::cout << *board;
}

Game::~Game()
{
	delete player1;
	delete player2;
	delete board;
}
