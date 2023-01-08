#include "Game.h"

Game::Game(GameRoom r)
{
    
    //m_board = Board(r.getRoomInfo().boardDimensions);
    //functie care adauga jucatorii din camera in vectorul de jucatori
    for (auto player : r.getPlayers())
    {
        m_players.push_back(player);
    }
}

void Game::AddPlayer(const Player& player)
{
	m_players.push_back(player);
}
void Game::SetPlayerAdvantages(const Player& player)
{
	std::array<uint8_t, 3>player_advantage;
	for (int i = 0; i < player_advantage.size(); i++)
	{
		player_advantage[i] = 1;
	}
	m_PlayersAdvantages.push_back(player_advantage);
}
uint8_t Game::DetermineNumberOfRounds(uint8_t n)
{
	uint8_t rounds;
	if (n == 2)
	{
		rounds = 5;
	}
	else
	{
		if (n == 3)
		{
			rounds = 4;
		}
		else
		{
			rounds = 4;
		}
	}
	return rounds;
}

void Game::DeterminePlayersTurnOrder()
{
	QuestionInt question(1,"În ce an s-a născut Regele Mihai I?", 1921);
	std::vector<int>answers;
	int answer;
	for (int i = 0; i < m_players.size(); i++)
	{
		std::cin >> answer;
		answers.push_back(answer);
	}
	for (int i = 0; i < m_players.size() - 1; i++)
	{
		for (int j = 0; j < m_players.size(); j++)
		{
			if (question.CheckAnswer(answers[i]) > question.CheckAnswer(answers[j]))
			{
				std::swap(answers[i], answers[j]);
				//std::swap(Players[i], Players[j]);
				//swap function of two players
			}
		}
	}
}
uint8_t Game::ChooseAdvantage(const Player& player, std::array<uint8_t, 3>& Advantage)
{
    uint8_t advantage;
    uint8_t unavailable_advantage = 4;
    int line, column;
    std::cin >> line >> column;
    std::cin >> advantage;
    //if (m_board[line][column].GetScore() >= 200 and Advantage[advantage] != 0)
    //{
        //uint32_t new_score;
       // new_score = m_board[line][column].GetScore() - 100;
        //m_board[line][column].SetScore(new_score);
        //Advantage[advantage] = 0;
        //return advantage;
    //}
    return unavailable_advantage;
}
void Game::ConquerTerritory(uint8_t line, uint8_t column, uint8_t order)
{

    //m_board[line][column].SetTerritoryColor(m_players[order].GetColor());

}
void Game::DistributeTerritory(uint8_t line, uint8_t column, uint8_t order)
{
    ConquerTerritory(line,column, order);
    //m_board[line][column].SetTerritoryScore(100);
}
std::unordered_map<std::string, bool> Game::FiftyFiftyAdvantage()
{
    uint8_t count = 2;
    std::string corect_answer;
    std::string answer2;
    std::string answer3;
    std::string answer4;
    std::cin >> corect_answer >> answer2 >> answer3 >> answer4;
    std::unordered_map<std::string, bool>question({ {corect_answer,0},{answer2,1},{answer3,1},{answer4,1} });
    question.erase(answer3);
    question.erase(answer4);
    return question;
}

std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> Game::ChooseAnswerAdvantage(QuestionInt question)
{
    std::tuple<uint16_t, uint16_t, uint16_t, uint16_t> answers;
    uint16_t corectAnswer = question.GetAnswer();
    uint16_t answer2 = question.GetAnswer() - 10;
    uint16_t answer3 = question.GetAnswer() + 10;
    uint16_t answer4 = question.GetAnswer() - 18;
    answers = std::make_tuple(corectAnswer, answer2, answer3, answer4);
    return answers;
}

uint16_t Game::SuggestAnswerAdvantage(QuestionInt question)
{
    uint16_t corectAnswer = question.GetAnswer();
    uint16_t closeAnswer1 = question.GetAnswer() - 5;
    uint16_t closeAnswer2 = question.GetAnswer() + 5;
    uint16_t closeAnswer3 = question.GetAnswer() + 3;
    uint8_t random= 1 + (rand() % 4);
    if (random==1)
    {
        return corectAnswer;
    }
    else
    {
        if (random==2)
        {
            return closeAnswer1;
        }
        else
        {
            if (random==3)
            {
                return closeAnswer2;
            }
            else
            {
                return closeAnswer3;
            }
        }
    }
}
