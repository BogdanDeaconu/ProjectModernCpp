#include "Player.h"
#include "Territory.h"


Player& Player::operator=(const Player& player)
{
	m_color = player.m_color;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os <<
		static_cast<std::string>(player.m_name) << " " <<
		static_cast<int>(player.m_color) << " " <<
		static_cast<uint32_t>(player.m_score) << std::endl;
}

Player::Player(const std::string& name, Color color, uint32_t score, Status status) :
	m_name(name),
	m_color(color),
	m_score(score),
	m_status(status)
{

}

Player::Player() :
	m_name(""),
	m_color(),
	m_score(),
	m_status()
{
}

Player::Color Player::GetColor() const
{
	return m_color;
}

void Player::SetName(const std::string& name)
{
	m_name = name;
}

std::string Player::GetName() const
{
	return m_name;
}

void Player::SetColor(const Player::Color& color)
{
	m_color = color;
}

void Player::SetScore(const uint32_t& score)
{
	m_score = score;
}

uint32_t Player::GetScore() const
{
	return m_score;
}

void Player::SetStatus(const Player::Status& status)
{
	m_status = status;
}

Player::Status Player::GetStatus() const
{
	return m_status;
}

int Player::PlayerAnswer()
{
	int answer;
	std::cin >> answer;
	return answer;
}

void Player::WinDuel()
{
	m_score = m_score + 100;
}

void Player::LoseDuel()
{
	m_score = m_score - 100;
}

void Player::setBase(Board::Position pos, Territory& base, const Player& player)
{
	base.ConquerTerritory(player.GetColor());
	base.SetTerritoryScore(300);
	//board[pos] = base;
}



