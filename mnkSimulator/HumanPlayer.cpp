#include "stdafx.h"
#include "HumanPlayer.h"
#include <regex>
#include <string>
#include <chrono>
#include <thread>
#include "Board.h"
#include "Common.h"

HumanPlayer::HumanPlayer(int m, int n, int k, int timeLimit, int playerNumber):
	Player(playerNumber, timeLimit)
{
}


Move* HumanPlayer::makeMove(Board * b, int timeLimit)
{	//text input won't work because of timer changing cursor position
	/*std::string input;
	bool valid = false;
	int m1, m2;
	std::regex re("[\D]*([\d]+)[\D]+([\d]+)[\D]*");
	while (!valid) {
		std::cout << "Enter any comma separated pair of integers in (row,col) format: ";
		std::getline(std::cin, input);
		std::smatch match;
		if (std::regex_search(input, match, re) && match.size() > 2) {
			m1 = std::stoi(match.str(1));
			m2 = std::stoi(match.str(2));
			valid = true;
		}
	}
	return new Move(m1, m2, getPlayerNumber());*/
	bool valid = false;
	int x, y, row,col, origx, origy;
	getCursorLoc(origx, origy);
	while (!valid) {
		getCursorLoc(x, y);
		char ch = getCursorChar();		
		if (ch == BoardSpaceToChar.at(BoardSpace::EMPTY)) {
			valid = true;
			std::cout << "VALID!";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	
	return new Move(1, 1, this);
}

const char * HumanPlayer::getName()
{
	return "Human";
}
