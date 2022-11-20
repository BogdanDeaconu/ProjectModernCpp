#include "Player.h"
#include "Territory.h"

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os <<
		static_cast<std::string>(player.m_name) << " " <<
		static_cast<int>(player.m_color);
}

Player::Player(const std::string& name, Color color) :
	m_name(name),
	m_color(color)
{
}

Player::Color Player::GetColor() const
{
	return m_color;
}

//Player& Player::operator=(Player&& player)
//{
	//m_color = player.m_color;
	//new (&player) Player;
	//return *this;
//}
