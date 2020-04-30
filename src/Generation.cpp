#include "Generation.h"

#include "Space.h"
#include "State.h"

Generation::Generation(const class State State, const class Space Space): CurrentState(State), Space(Space), GenerationId(1)
{
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
	std::vector<Cell> NewCells;

	for (int HeightIndex = 0; HeightIndex < Space.GetHeight(); HeightIndex++) {
		for (int WidthIndex = 0; WidthIndex < Space.GetWidth(); WidthIndex++) {
			if (IsAliveCellInNextGeneration(WidthIndex, HeightIndex)) {
				NewCells.emplace_back(WidthIndex, HeightIndex);
			}
		}
	}

	CurrentState = State(std::make_shared<std::vector<Cell>>(NewCells));
	GenerationId++;
}

bool Generation::IsAliveCellInNextGeneration(const int X, const int Y) const
{
	const int Neighbours = CurrentState.GetNeighboursByPosition(X, Y)->size();

	if (CurrentState.PositionIsAliveCell(X, Y) && Neighbours == 2 || Neighbours == 3) {
		return true;
	}

	if (!CurrentState.PositionIsAliveCell(X, Y) && Neighbours == 3) {
		return true;
	}

	return false;
}
