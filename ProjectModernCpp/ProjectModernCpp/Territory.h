#pragma once
#include<cstdint>
class Territory
{
public:
	//Color Grey means unconquered territory
	enum class Color : uint8_t
	{
		Blue,
		Red,
		Yellow,
		Green,
		Gray
	};
public:
	
	Territory(const uint16_t score, Color color);
	Territory GetTerritory(const Territory& territory);
	void ConquerTerritory(Color color);
private:
	const uint16_t m_score;
	Color m_color;
};

