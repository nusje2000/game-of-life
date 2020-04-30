#include "Random.h"

#include <ctime>

State Random::CreateState(const Space Space, const int AliveProbability)
{
	std::vector<Cell> InitialCells;

	srand(time(nullptr));
	for (int HeightIndex = 0; HeightIndex < Space.GetHeight(); HeightIndex++) {
		for (int WidthIndex = 0; WidthIndex < Space.GetWidth(); WidthIndex++) {
			if (rand() % 100 + 1 <= AliveProbability) {
				InitialCells.emplace_back(WidthIndex, HeightIndex);
			}
		}
	}

	return State(std::make_shared<std::vector<Cell>>(InitialCells));
}
