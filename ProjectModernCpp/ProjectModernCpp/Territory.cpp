#include "Territory.h"


Territory::Territory(const uint32_t score, Color color) :
    m_score(score),
	m_color(color)
{ }

Territory::Territory() :
	m_score(0),
	m_color(Color::Grey)

{
}



void Territory::SetTerritoryColor(Color color)
{
	m_color = color;
}

Color Territory::GetColor() const
{
	return m_color;
}

uint32_t Territory::GetScore() const
{
	return m_score;
}

void Territory::SetTerritoryScore(uint32_t n)
{
	m_score = n;
}

std::ostream& operator<<(std::ostream& out, const Territory& territory)
{
	return out << "Score: " << territory.m_score << " " << "Color: " << static_cast<int> (territory.m_color);
}
