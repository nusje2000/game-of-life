#include "Renderer.h"

#include <iostream>

void Renderer::Render(const Generation& Generation)
{
	std::cout << "\033\143";


	for (int HeightIndex = 0; HeightIndex < Generation.GetSpace().GetHeight(); HeightIndex++) {
		for (int WidthIndex = 0; WidthIndex < Generation.GetSpace().GetWidth(); WidthIndex++) {
			if (Generation.GetState().PositionIsAliveCell(WidthIndex, HeightIndex)) {
				std::cout << "[]";
			} else {
				std::cout << "  ";
			}
		}

		std::cout << std::endl;
	}

	std::cout << "Generation: " << Generation.GetGenerationId() << std::endl;
	std::cout.flush();
}
