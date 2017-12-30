#pragma once
#include <map>
#include <string>
#include <vector>
enum class BoardSpace {
	EMPTY,
	PLAYER1PIECE,
	PLAYER2PIECE
};

enum class PlayerType {
	HUMAN,
	SAMPLEAI
};
void setCursorPosition(int, int);
void getCursorLoc(int&, int&);
char getCursorChar();

const std::vector < std::string > playerNames = { "Human","SampleAI" };
const std::map<std::string,PlayerType> playerNameToType = { { "Human",PlayerType::HUMAN },{ "SampleAI", PlayerType::SAMPLEAI} };
const std::map<BoardSpace, char> BoardSpaceToChar = { { BoardSpace::EMPTY,'.' },{ BoardSpace::PLAYER1PIECE, 'X' },{ BoardSpace::PLAYER2PIECE , 'O' } };