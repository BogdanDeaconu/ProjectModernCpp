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
	void SetBoardDimensions(int n);
	std::size_t GetHeight();
	std::size_t GetWidth();
	void SetHeight(std::size_t height);
	void SetWidth(std::size_t width);

private:
	std::vector<Territory>m_board;
	std::size_t m_height;
	std::size_t m_width;
	std::size_t m_size;
	int m_NumberOfPlayers;
};

