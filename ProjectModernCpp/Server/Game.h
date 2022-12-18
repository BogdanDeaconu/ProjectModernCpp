#pragma once
#include"QuestionBool.h"
#include"QuestionInt.h"
class Game
{
public:
	void AddPlayer(const Player& player);
	void SetPlayerAdvantages(const Player& player);
	uint8_t DetermineNumberOfRounds(uint8_t n);
private:
	std::vector<QuestionBool*>m_questionswithboool;
	std::vector<QuestionInt*>m_questionswithinteger;
	std::vector<Player>m_players;
	Board m_board;
	std::vector<std::array<uint8_t, 3>>m_PlayersAdvantages;
};

