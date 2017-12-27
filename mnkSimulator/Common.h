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

const std::vector < std::string > playerNames = { "Human","SampleAI" };
const std::map<std::string,PlayerType> playerNameToType = { { "Human",PlayerType::HUMAN },{ "SampleAI", PlayerType::SAMPLEAI} };