#include "State.h"

#include <algorithm>

const std::vector<unsigned int>& State::GetCells() const
{
	return Cells;
}

int State::GetNeighboursCountByPosition(const unsigned int Index) const
{
	int NeighbourCount = 0;
	const std::unique_ptr<std::vector<unsigned int>> Neighbours = GetNeighboursIndexesByPosition(Index);

	for (int Iteration = 0; Iteration < Neighbours->size(); Iteration++) {
		NeighbourCount += PositionIsAliveCell(Neighbours->at(Iteration));
	}

	return NeighbourCount;
}

std::unique_ptr<std::vector<unsigned int>> State::GetNeighboursIndexesByPosition(const unsigned Index) const
{
	std::vector<unsigned int> Neighbours;

	const unsigned short X = GetXFromIndex(Index);
	const unsigned short Y = GetYFromIndex(Index);

	if (X != 0) {
		Neighbours.emplace_back(CreateIndex(X - 1, Y));
		Neighbours.emplace_back(CreateIndex(X - 1, Y + 1));
	}

	if (Y != 0) {
		Neighbours.emplace_back(CreateIndex(X, Y - 1));
		Neighbours.emplace_back(CreateIndex(X + 1, Y - 1));
	}

	if (X != 0 && Y != 0) {
		Neighbours.emplace_back(CreateIndex(X - 1, Y - 1));
	}

	Neighbours.emplace_back(CreateIndex(X + 1, Y));
	Neighbours.emplace_back(CreateIndex(X + 1, Y + 1));
	Neighbours.emplace_back(CreateIndex(X, Y + 1));

	return std::make_unique<std::vector<unsigned int>>(Neighbours);
}

bool State::PositionIsAliveCell(const unsigned short X, const unsigned short Y) const
{
	const int Index = CreateIndex(X, Y);

	return PositionIsAliveCell(Index);
}

bool State::PositionIsAliveCell(const unsigned Index) const
{
	return std::binary_search(Cells.begin(), Cells.end(), Index);
}

void State::SetAliveCell(const unsigned short X, const unsigned short Y)
{
	Cells.emplace_back(CreateIndex(X, Y));
}

void State::SetAliveCell(const unsigned Index)
{
	Cells.emplace_back(Index);
}

void State::Sort()
{
	std::sort(Cells.begin(), Cells.end());
}

unsigned short State::GetXFromIndex(const unsigned int Index) const
{
	return Index >> 16;
}

unsigned short State::GetYFromIndex(const unsigned int Index) const
{
	return Index;
}

int State::CreateIndex(const unsigned short X, const unsigned short Y) const
{
	return (int(X) << 16) + Y;
}
