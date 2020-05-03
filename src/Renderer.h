#pragma once

#include "Generation.h"
#include <cstdlib>
#include <windows.h>

class Renderer
{
public:
	Renderer();

	void Render(const Generation& Generation);

private:
	const HWND Console;
	const HDC Context;
	State PreviousState;
};
