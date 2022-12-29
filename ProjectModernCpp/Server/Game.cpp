#include "Game.h"

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