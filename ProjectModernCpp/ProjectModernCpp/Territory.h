#pragma once
#include<cstdint>
#include<iostream>
#include"Player.h"
class Territory
{
public:
	enum class Color : uint8_t
	{
		Blue,
		Red,
		Yellow,
		Green
	};
public:
	
	Territory(const uint16_t score, Color color);
	Territory();

	Territory::Color GetColor() const;
	Territory GetTerritory(const Territory& territory);
	void SetTerritoryScore(uint32_t n);
	friend std::ostream& operator<<(std::ostream& out, const Territory& territory);
private:
	uint32_t m_score;
	Color m_color;
};

