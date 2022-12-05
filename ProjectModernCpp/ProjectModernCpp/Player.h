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
	Player();
	Player& operator=(Player&& player);
	Color GetColor() const;
	
	friend std::ostream& operator <<(std::ostream& os, const Player& player);
	void setBase(Board::Position pos, Territory& base, const Player& player);
	void setInactivePlayer(Player player, Territory base);
	void SetName(const std::string& name);
	void SetColor(const Player::Color& color);
	
	int PlayerAnswer();
	
private:
	std::string m_name;
	Color m_color;
	Board board;

};

