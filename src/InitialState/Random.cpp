#include "Random.h"

#include <ctime>

std::unique_ptr<State> Random::CreateState(const Space Space, const int AliveProbability)
{
	State InitialState;

	srand(time(nullptr));

	for (int HeightIndex = 0; HeightIndex < Space.GetHeight(); HeightIndex++) {
		for (int WidthIndex = 0; WidthIndex < Space.GetWidth(); WidthIndex++) {
			if (rand() % 100 + 1 <= AliveProbability) {
				InitialState.SetAliveCell(WidthIndex, HeightIndex);
			}
		}
	}

	return std::make_unique<State>(InitialState);
}
