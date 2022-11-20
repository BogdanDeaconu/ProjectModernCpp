#include "Territory.h"


Territory::Territory(const uint16_t score, Color color) :
	m_score(score),
	m_color(color)
{

}

Territory Territory::GetTerritory(const Territory& territory)
{
	return territory;
}

Territory::Color Territory::GetColor() const
{
	return m_color;
}

void Territory::ConquerTerritory(Player::Color color)
{
	m_color = static_cast<Territory::Color>(color);
}

void Territory::SetTerritoryScore(uint32_t n)
{
	m_score = n;
}

std::ostream& operator<<(std::ostream& out, const Territory& territory)
{
	return out << "Score: " << territory.m_score << " " << "Color: " << static_cast<int> (territory.m_color);
}
