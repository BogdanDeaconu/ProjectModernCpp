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
	enum class Status :uint8_t
	{
		Inactiv,
		Activ
	};

public:
	Player(const std::string& name, Color color, uint32_t score, Status status);
	Player();
	Player& operator=(const Player& player);
	friend std::ostream& operator <<(std::ostream& os, const Player& player);
	void SetName(const std::string& name);
	std::string GetName() const;
	void SetColor(const Player::Color& color);
	Color GetColor() const;
	void SetScore(const uint32_t& score);
	uint32_t GetScore() const;
	void SetStatus(const Player::Status& status);
	Status GetStatus() const;
	int PlayerAnswer();
	void WinDuel();
	void LoseDuel();

private:
	std::string m_name;
	Color m_color;
	uint32_t m_score;
	Status m_status;

};


