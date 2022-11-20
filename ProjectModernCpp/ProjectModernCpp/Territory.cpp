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

void Territory::ConquerTerritory(Color color)
{
	m_color = color;
}

std::ostream& operator<<(std::ostream& out, const Territory& territory)
{
	return out << "Score: " << territory.m_score << " " << "Color: " << static_cast<int> (territory.m_color);
}
