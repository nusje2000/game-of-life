#include "Renderer.h"

#include <iostream>
#include <map>
#include <windows.h>

Renderer::Renderer(): Console(GetConsoleWindow()), Context(GetDC(Console))
{
	HideCaret(Console);
}

void Renderer::Render(const Generation& Generation)
{
	const auto AliveCellColor = RGB(255, 0, 0);
	const auto DeadCellColor = RGB(0, 0, 0);

	std::map<unsigned int, bool> Pixels;
	
	for (const unsigned int Index : PreviousState.GetCells()) {
		Pixels.emplace(Index, false);
	}

	const State State = Generation.GetState();
	for (const unsigned int Index : State.GetCells()) {
		Pixels.emplace(Index, true);
	}

	auto Iterator = Pixels.begin();
	while (Iterator != Pixels.end()) {
		SetPixel(Context, State.GetXFromIndex(Iterator->first), State.GetYFromIndex(Iterator->first), Iterator->second ? AliveCellColor : DeadCellColor);
		++Iterator;
	}

	PreviousState = State;
}
