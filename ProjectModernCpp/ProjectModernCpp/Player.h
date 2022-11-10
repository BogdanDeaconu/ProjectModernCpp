#pragma once
#include <iostream>
#include <string>

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
	friend std::ostream& operator <<(std::ostream& os, const Player& player);

private:
	std::string m_name;
	Color m_color;


};

