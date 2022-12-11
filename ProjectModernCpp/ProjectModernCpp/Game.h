#include <array>
#include <time.h>
#include <fstream>
#include <random>

#include "QuestionWithBool.h"
#include "QuestionWithInteger.h"
#include"Board.h"
#include"Player.h"
class Game  
{

public:
	Game();
	
	QuestionWithBool* GetBoolQuestion();
	QuestionWithInteger* GetIntegerQuestion();
	
	void ReadIntQ(std::vector <QuestionWithInteger *>& Intquestions);
	void ReadBoolQ(std::vector <QuestionWithBool*>& Boolquestions);
	
	void Duel(int order1, int order2);

	void DeterminePlayersTurnOrder();
	void ConquerTerritory(Board::Position pos, int order);
	void DistributeTerritory(Board::Position pos,int order);
	void ChooseAdvantage(std::vector<int>& Advantage,uint8_t advantage);
	
	void StartGame(int PlayersNumber);
private:
	static const std::size_t numberOfBoolQ = 70;
	static const std::size_t number0fIntQ = 30;
private:
	std::vector<QuestionWithBool*>m_questionswithboool;
	std::vector<QuestionWithInteger*>m_questionswithinteger;
	std::vector<Player>m_players;
	Board m_board;
};


