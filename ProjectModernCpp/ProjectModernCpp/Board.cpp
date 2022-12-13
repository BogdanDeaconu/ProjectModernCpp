#include "Board.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	Board::Position pos;
	auto& [line, column] = pos;
	
	for ( line = 0; line < board.m_height; line++)
	{
		for (column = 0; column < board.m_width; column++)
		{
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
	NumberOfPlayers = n;
}

int Board::GetNumberOfPlayers()
{
	return NumberOfPlayers;
}

void Board::SetBoardDimensions(int n)
{
	if (m_NumberOfPlayers == 2)
	{
		m_height = 3;
		m_width = 3;
	}
	
	else
	{
		if (m_NumberOfPlayers == 3)
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





