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
	SAMPLEAI,
	ALPHABETAAI
};
void setCursorPosition(int, int);
void getCursorLoc(int&, int&);
char getCursorChar();

const std::vector < std::string > playerNames = { "Human","SampleAI","AlphaBetaAI" };
const std::map<std::string,PlayerType> playerNameToType = { { "Human",PlayerType::HUMAN },{ "SampleAI", PlayerType::SAMPLEAI},{ "AlphaBetaAI", PlayerType::ALPHABETAAI } };
const std::map<BoardSpace, char> BoardSpaceToChar = { { BoardSpace::EMPTY,'.' },{ BoardSpace::PLAYER1PIECE, 'X' },{ BoardSpace::PLAYER2PIECE , 'O' } };