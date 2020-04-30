#include "State.h"

#include <algorithm>

int State::GetNeighboursCountByPosition(const unsigned short X, const unsigned short Y) const
{
	return
		PositionIsAliveCell(X - 1, Y - 1) +
		PositionIsAliveCell(X, Y - 1) + 
		PositionIsAliveCell(X + 1, Y - 1) + 
		PositionIsAliveCell(X - 1, Y) +
		PositionIsAliveCell(X + 1, Y) +
		PositionIsAliveCell(X - 1, Y + 1) +
		PositionIsAliveCell(X, Y + 1) +
		PositionIsAliveCell(X + 1, Y + 1);
}

bool State::PositionIsAliveCell(const unsigned short X, const unsigned short Y) const
{
	const int Index = CreateIndex(X, Y);

	return std::binary_search(Cells.begin(), Cells.end(), Index);
}

void State::SetAliveCell(const unsigned short X, const unsigned short Y)
{
	Cells.emplace_back(CreateIndex(X, Y));
}

void State::Sort()
{
	std::sort(Cells.begin(), Cells.end());
}

int State::CreateIndex(const unsigned short X, const unsigned short Y) const
{
	return (int(X) << 16) + Y;
}
