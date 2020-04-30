#include "Generation.h"

#include "Space.h"
#include "State.h"

Generation::Generation(const class State State, const class Space Space): CurrentState(State), Space(Space), GenerationId(1)
{
	CurrentState.Sort();
}

const State& Generation::GetState() const
{
	return CurrentState;
}

const Space& Generation::GetSpace() const
{
	return Space;
}

int Generation::GetGenerationId() const
{
	return GenerationId;
}

void Generation::Evolve()
{
	State NewState;

	std::vector<unsigned int> CheckCells;

	const std::vector<unsigned int> CurrentCells = CurrentState.GetCells();
	for (int Index = 0; Index < CurrentCells.size(); Index++) {
		std::unique_ptr<std::vector<unsigned int>> NewCheckCells = CurrentState.GetNeighboursIndexesByPosition(CurrentCells[Index]);
		NewCheckCells->emplace_back(CurrentCells[Index]);

		for (int NewCellIndex = 0; NewCellIndex < NewCheckCells->size(); NewCellIndex++) {
			if (std::find(CheckCells.begin(), CheckCells.end(), NewCheckCells->at(NewCellIndex)) == CheckCells.end()) {
				CheckCells.emplace_back(NewCheckCells->at(NewCellIndex));
			}
		}
	}

	for (int Index = 0; Index < CheckCells.size(); Index++) {
		if (IsAliveCellInNextGeneration(CheckCells.at(Index))) {
			NewState.SetAliveCell(CheckCells.at(Index));
		}
	}

	NewState.Sort();
	CurrentState = NewState;
	GenerationId++;
}

bool Generation::IsAliveCellInNextGeneration(const unsigned int Index) const
{
	if (CurrentState.GetXFromIndex(Index) > Space.GetWidth() || CurrentState.GetYFromIndex(Index) > Space.GetHeight()) {
		return false;
	}

	const int Neighbours = CurrentState.GetNeighboursCountByPosition(Index);

	return CurrentState.PositionIsAliveCell(Index) ? Neighbours == 2 || Neighbours == 3 : Neighbours == 3;
}
