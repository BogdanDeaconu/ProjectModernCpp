#include "Board.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	Board::Position pos;
	auto& [line, column] = pos;
	for ( line = 0; line < board.m_height; line++)
	{
		for (column = 0; column <board.m_width; column++){
		
			if (board[pos].GetColor()!=Color::Grey)
			{
				out << board[pos];
			}
			else
			{
				out << "Unconquered Territory";
			}
			out << " ";
		}
		out << std::endl;
	}
	return out;
}

const Territory& Board::operator[](Position pos) const
{
	const auto& [line, column] = pos;
	return m_board[line * m_width + column];
}

Territory& Board::operator[](Position pos)
{
	const auto& [line, column] = pos;
	return m_board[line * m_width + column];
}

void Board::ChooseNumberOfPlayers(int n)
{
	m_NumberOfPlayers = n;
}

int Board::GetNumberOfPlayers()
{
	return m_NumberOfPlayers;
}

void Board::SetBoardDimensions(int n)
{
	if (n == 2)
	{
		m_height = 3;
		m_width = 3;
	}
	
	else
	{
		if (n == 3)
		{
			m_height = 5;
			m_width = 3;
		}
		else
		{
			m_height = 6;
			m_width = 4;
		}
	}
	m_size = m_height * m_width;

}

std::size_t Board::GetHeight()
{
	return m_height;
}

std::size_t Board::GetWidth()
{
	return m_width;
}

void Board::SetHeight(std::size_t height)
{
	m_height = height;
}

void Board::SetWidth(std::size_t width)
{
	m_width = width;
}





