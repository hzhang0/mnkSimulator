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


Move* HumanPlayer::makeMove(Board b, int timeLimit, const Player* otherPlayer){
	std::string input;
	bool valid = false;
	int m1, m2;
	std::regex re("[\\D]*([\\d]+)[\\D]+([\\d]+)[\\D]*");
	while (!valid) {
		std::cout << "Enter any comma separated pair of integers in (row,col) format: ";
		std::cin.sync();
		std::getline(std::cin, input);
		std::smatch match;
		//if (input == "Time's up!") { //this is surprisingly not necessary
		//	break;
		//}		
		if (std::regex_search(input, match, re) && match.size() > 1) {
			m1 = std::stoi(match.str(1));
			m2 = std::stoi(match.str(2));			
			valid = true;
		}
	}
	return new Move(m2, m1, getPlayerNumber());
}

const char * HumanPlayer::getName()
{
	return "Human";
}
