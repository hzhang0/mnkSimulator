#include "stdafx.h"
#include "HumanPlayer.h"
#include <regex>
#include <string>
#include <chrono>
#include <thread>
#include "Board.h"
#include "Common.h"
#include <conio.h>

HumanPlayer::HumanPlayer(int m, int n, int k, int timeLimit, int playerNumber):
	Player(playerNumber, timeLimit)
{
}

/*bool getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}*/

Move HumanPlayer::makeMove(Board b, int timeLimit, const Player* otherPlayer, std::atomic<bool>* timesUp){
	std::string input;
	bool valid = false;
	int m1, m2;
	std::regex re("[\\D]*([\\d]+)[\\D]+([\\d]+)[\\D]*");
	while (!valid) {
		std::cout << "Enter any comma separated pair of integers in (row,col) format: ";
		std::cin.sync();
		std::getline(std::cin, input);
		/*char key = ' ';
		while ((key != '\n') && (key != '\r')) {
			getInput(&key);
			if (*timesUp) {
				return Move();
			}
		}
		std::getline(std::cin, input);*/
		std::smatch match;
		if (std::regex_search(input, match, re) && match.size() > 1) {
			m1 = std::stoi(match.str(1));
			m2 = std::stoi(match.str(2));			
			valid = true;
		}
	}
	return Move(m2, m1, getPlayerNumber());
}

const char * HumanPlayer::getName()
{
	return "Human";
}
