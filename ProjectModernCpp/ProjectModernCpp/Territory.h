#pragma once
#include<cstdint>
#include<iostream>
#include"Player.h"
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
		Grey
	};
public:
	
	Territory(const uint16_t score, Color color);
	Territory GetTerritory(const Territory& territory);
	Color GetColor() const;
	void ConquerTerritory(Player::Color color);
	void SetTerritoryScore(uint32_t n);
	friend std::ostream& operator<<(std::ostream& out, const Territory& territory);
private:
	uint32_t m_score;
	Color m_color;
};

