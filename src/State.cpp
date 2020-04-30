#include "State.h"

State::State(const std::shared_ptr<std::vector<Cell>> Cells): Cells(Cells)
{
}

std::shared_ptr<std::vector<Cell>> State::GetNeighboursByPosition(const int X, const int Y) const
{
	std::vector<Cell> Neighbours;
	for (int Index = 0; Index < Cells->size(); Index++) {
		const Cell& CurrentCell = Cells->at(Index);
		if (CurrentCell.GetX() == X && CurrentCell.GetY() == Y) {
			continue;
		}

		if (CurrentCell.GetX() >= X - 1 && CurrentCell.GetX() <= X + 1 && CurrentCell.GetY() >= Y - 1 && CurrentCell.GetY() <= Y + 1) {
			Neighbours.emplace_back(CurrentCell);
		}
	}

	return std::make_shared<std::vector<Cell>>(Neighbours);
}

bool State::PositionIsAliveCell(const int X, const int Y) const
{
	for (int Index = 0; Index < Cells->size(); Index++) {
		const Cell& CurrentCell = Cells->at(Index);

		if (CurrentCell.GetX() == X && CurrentCell.GetY() == Y) {
			return true;
		}
	}

	return false;
}
