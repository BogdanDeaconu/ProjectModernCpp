#include "Board.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	Board::Position pos;
	auto& [line, column] = pos;
	for ( line = 0; line < Board::height; line++)
	{
		for (column = 0; column < Board::width; column++)
		{
			if (board[pos])
			{
				out << *board[pos];
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

const std::optional<Player>& Board::operator[](Position pos) const
{
	const auto& [line, column] = pos;
	return m_board[line * width + column];
}

std::optional<Player>& Board::operator[](Position pos)
{
	const auto& [line, column] = pos;
	return m_board[line * width + column];
}
