#pragma once
#include"Player.h"
#include<array>
#include<optional>
#include<cstdint>
class Board
{
public:
	using Position = std::pair<uint8_t, uint8_t>;

public:
	
	friend std::ostream& operator<<(std::ostream& out, const Board& board);

private:
	static const std::size_t height = 3;
	static const std::size_t width = 3;
	static const std::size_t size = height * width;

private:
	std::array<std::optional<Player>, size>m_board;
};

