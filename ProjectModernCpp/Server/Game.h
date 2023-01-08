#pragma once
#include"QuestionBool.h"
#include"QuestionInt.h"
#include"Player.h"
#include<array>
#include<tuple>
#include "GameRoom.h"
class Game
{
public:
    Game(GameRoom r);
	void AddPlayer(const Player& player);
	void SetPlayerAdvantages(const Player& player);
	uint8_t DetermineNumberOfRounds(uint8_t n);
	void DeterminePlayersTurnOrder();
    uint8_t ChooseAdvantage(const Player& player, std::array<uint8_t, 3>& Advantage);
    void ConquerTerritory(uint8_t line,uint8_t column, uint8_t order);
    void DistributeTerritory(uint8_t line, uint8_t column, uint8_t order);
    std::unordered_map<std::string, bool> FiftyFiftyAdvantage();
    std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> ChooseAnswerAdvantage(QuestionInt question);
    uint16_t SuggestAnswerAdvantage(QuestionInt question);
private:
	std::vector<QuestionBool*>m_questionswithboool;
	std::vector<QuestionInt*>m_questionswithinteger;
	std::vector<Player>m_players;
	std::vector<std::array<uint8_t, 3>>m_PlayersAdvantages;
    //Board m_board;
};

