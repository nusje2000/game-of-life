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

	for (int HeightIndex = 0; HeightIndex < Space.GetHeight(); HeightIndex++) {
		for (int WidthIndex = 0; WidthIndex < Space.GetWidth(); WidthIndex++) {
			if (IsAliveCellInNextGeneration(WidthIndex, HeightIndex)) {
				NewState.SetAliveCell(WidthIndex, HeightIndex);
			}
		}
	}

	NewState.Sort();
	CurrentState = NewState;
	GenerationId++;
}

bool Generation::IsAliveCellInNextGeneration(const int X, const int Y) const
{
	const int Neighbours = CurrentState.GetNeighboursCountByPosition(X, Y);

	return CurrentState.PositionIsAliveCell(X, Y) ? Neighbours == 2 || Neighbours == 3 : Neighbours == 3;
}
