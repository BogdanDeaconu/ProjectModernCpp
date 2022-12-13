#pragma once

#include<vector>
#include<optional>
#include<cstdint>
#include<array>
#include"Territory.h"

class Board
{
public:
	using Position = std::pair<uint8_t, uint8_t>;

public:
	//getter
	const Territory& operator[](Position pos) const;
	//setter
	Territory& operator[](Position  pos);
	
	friend std::ostream& operator<<(std::ostream& out, const Board& board);
	
	void ChooseNumberOfPlayers(int n);
	int GetNumberOfPlayers();
	void SetBoardDimensions();
	

private:
	std::size_t m_height;
	std::size_t m_width;
	std::size_t m_size;
	int NumberOfPlayers;
	std::vector<Territory>m_board;
};

