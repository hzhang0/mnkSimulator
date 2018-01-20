#pragma once
#include <map>
#include "Common.h"
#include <string>
#include <algorithm>
std::map<int, BoardSpace> playerNumToType = { { 1, BoardSpace::PLAYER1PIECE },{ 2, BoardSpace::PLAYER2PIECE } };

class Player;
#include "HumanPlayer.h"
#include "SampleAI.h"
#include "AlphaBetaAI.h"
template< typename T > 
Player* fCreate(int m, int n, int k, int timeLimit, int playerNumber) {
	return new T(m, n, k, timeLimit, playerNumber);
}

typedef Player* (*tConstructor)(int m, int n, int k, int timeLimit, int playerNumber);
struct Mapping {
	PlayerType playerType;
	tConstructor constructor;

	operator std::pair<PlayerType, tConstructor>() const {
		return std::make_pair(playerType, constructor);
	}
} mapping[] =
{ { PlayerType::HUMAN, &fCreate<HumanPlayer> }
,{PlayerType::SAMPLEAI, &fCreate<SampleAI> }
,{ PlayerType::ALPHABETAAI, &fCreate<AlphaBetaAI> }
// , ...
};