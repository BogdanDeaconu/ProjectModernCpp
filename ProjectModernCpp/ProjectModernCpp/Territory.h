#pragma once
#include<cstdint>
#include<iostream>
#include "Colors.h"

class Territory
{

public:
	
	Territory(const uint32_t score, Color color);
	Territory();
	Color GetColor() const;
	uint32_t GetScore() const;
	void SetTerritoryColor(Color color);
	void SetTerritoryScore(uint32_t n);
	friend std::ostream& operator<<(std::ostream& out, const Territory& territory);
private:
	uint32_t m_score;
	Color m_color;
};

