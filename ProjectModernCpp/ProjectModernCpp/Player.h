#pragma once
#include <iostream>
#include <string>
#include "Territory.h"
#include "Board.h"
#include "Game.h"

class Player
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
	Player(const std::string& name, Color color);
	Color GetColor() const;
	friend std::ostream& operator <<(std::ostream& os, const Player& player);
	
private:
	std::string m_name;
	Color m_color;
	Board board;

};

