#include "stdafx.h"
#include "Game.h"
#include "Common.h"
#include "Player.h"
#include "GameManager.h"
#include <chrono>
#include <thread>
#include <future>
#include <algorithm>

Game::Game(int m, int n, int k, int timeLimit, Player * p1, Player * p2):
	board(m, n, k)
{
	this->m = m;
	this->n = n;
	this->k = k;
	this->timeLimit = timeLimit;
	this->player1 = p1;
	this->player2 = p2;	
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


void timer(int timeLimit, std::atomic<bool>* running) {
	int origX, origY;
	for (int i = timeLimit; i>=0; i-=250)
	{
		getCursorLoc(origX, origY);
		setCursorPosition(6, 0);
		std::cout << (std::max(0, i)) << " ms        ";
		setCursorPosition(origX, origY);
		if (!(*running) || i <= 0) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void Game::startGame()
{
	clearScreen();
	//std::cout << "Player 1: " << player1->getName() << std::endl;
	//std::cout << "Player 2: " << player2->getName() << std::endl;
	//std::cout << "Starting game..." << std::endl;	
	auto curPlayer = player1;
	auto otherPlayer = player2;
	EndState es = GameManager::isTerminal(board);
	int move{ 1 };
	while (es == EndState::NOT_TERMINAL) {
		std::cout << "Time:         " << std::endl;
		std::cout << "Move " << move << std::endl;
		std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", to move." << std::endl << std::endl;
		std::cout << board;

		std::atomic<bool> running{ true };
		auto future = std::async(std::launch::async, timer, timeLimit, &running);
		std::this_thread::sleep_for(std::chrono::milliseconds(10)); //avoids conflict between outputs
		auto future2 = std::async(std::launch::async, &(Player::makeMove), curPlayer, board, timeLimit, otherPlayer);
		while (future2.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout) { //if comp finishes before timer, stop
			if (future.wait_for(std::chrono::milliseconds(100)) != std::future_status::timeout) { //if timer is up, break
				break;
			}
		}		
		running = false;
		Move* m;
		if (future2.wait_for(std::chrono::milliseconds(100)) == std::future_status::timeout) { //if computation is still not done
			std::cout << "Time's up!" << std::endl;
			m = GameManager::getValidMoves(board, curPlayer)->at(0);
			std::cout << "Assigned random move (" << m->getY() << ", " << m->getX() << ")." << std::endl;
		}
		else {
			std::this_thread::sleep_for(std::chrono::milliseconds(250)); //wait one full cycle of timer for it to move cursor back to end
			m = future2.get();
			std::cout << "Received move (" << m->getY()<< ", " << m->getX() << ")." << std::endl;
			if (!GameManager::isValidMove(board, m, curPlayer)) {
				std::cout << "Move is invalid!" << std::endl;
				m = GameManager::getValidMoves(board, curPlayer)->at(0);
				std::cout << "Assigned random move (" << m->getY() << ", " << m->getX() << ")." << std::endl;
			}
		}			
		std::this_thread::sleep_for(std::chrono::seconds(2)); //allow person to look at move
		board = GameManager::simulateMove(board, m, curPlayer);
		es = GameManager::isTerminal(board);
		clearScreen();
		if (es == EndState::NOT_TERMINAL) {
			swap(curPlayer, otherPlayer);
			move++;
		}
	}

	switch (es) {
		case EndState::DRAW:
			std::cout << "The game ends in a draw." << std::endl;
			break;
		case EndState::PLAYER1_WINS:
			//std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", loses." << std::endl;
			//std::cout << "Player " << otherPlayer->getPlayerNumber() << ", " << otherPlayer->getName() << ", wins." << std::endl;
			std::cout << "Player 1" << ", " << player1->getName() << ", wins." << std::endl;
			std::cout << "Player 2" << ", " << player2->getName() << ", loses." << std::endl;
			break;
		case EndState::PLAYER2_WINS:
			//std::cout << "Player " << curPlayer->getPlayerNumber() << ", " << curPlayer->getName() << ", wins." << std::endl;
			//std::cout << "Player " << otherPlayer->getPlayerNumber() << ", " << otherPlayer->getName() << ", loses." << std::endl;
			std::cout << "Player 1" << ", " << player1->getName() << ", loses." << std::endl;
			std::cout << "Player 2" << ", " << player2->getName() << ", wins." << std::endl;
			break;
	}
	std::cout << board;
}

Game::~Game()
{
	delete player1;
	delete player2;
}
