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
