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
