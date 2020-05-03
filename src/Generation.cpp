#include "Generation.h"
#include <set>
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

	std::set<unsigned int> CheckCells;

	const std::vector<unsigned int> CurrentCells = CurrentState.GetCells();
	for (int Index = 0; Index < CurrentCells.size(); Index++) {
		std::unique_ptr<std::vector<unsigned int>> NewCheckCells = CurrentState.GetNeighboursIndexesByPosition(CurrentCells[Index]);

		CheckCells.insert(CurrentCells[Index]);
		for (int NewCellIndex = 0; NewCellIndex < NewCheckCells->size(); NewCellIndex++) {
			CheckCells.insert(NewCheckCells->at(NewCellIndex));
		}
	}

	auto Iterator = CheckCells.begin();
	while (Iterator != CheckCells.end()) {
		if (IsAliveCellInNextGeneration(*Iterator)) {
			NewState.SetAliveCell(*Iterator);
		}
		++Iterator;
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
