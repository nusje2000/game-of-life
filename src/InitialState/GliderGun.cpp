#include "GliderGun.h"

#include <memory>

std::unique_ptr<State> GliderGun::CreateState()
{
	State InitialState;
	InitialState.SetAliveCell(3, 7);
	InitialState.SetAliveCell(4, 7);
	InitialState.SetAliveCell(3, 8);
	InitialState.SetAliveCell(4, 8);

	InitialState.SetAliveCell(13, 7);
	InitialState.SetAliveCell(13, 8);
	InitialState.SetAliveCell(13, 9);
	InitialState.SetAliveCell(14, 6);
	InitialState.SetAliveCell(14, 10);
	InitialState.SetAliveCell(15, 5);
	InitialState.SetAliveCell(15, 11);
	InitialState.SetAliveCell(16, 5);
	InitialState.SetAliveCell(16, 11);
	InitialState.SetAliveCell(17, 8);
	InitialState.SetAliveCell(18, 6);
	InitialState.SetAliveCell(18, 10);
	InitialState.SetAliveCell(19, 7);
	InitialState.SetAliveCell(19, 8);
	InitialState.SetAliveCell(19, 9);
	InitialState.SetAliveCell(20, 8);

	InitialState.SetAliveCell(23, 5);
	InitialState.SetAliveCell(23, 6);
	InitialState.SetAliveCell(23, 7);
	InitialState.SetAliveCell(24, 5);
	InitialState.SetAliveCell(24, 6);
	InitialState.SetAliveCell(24, 7);
	InitialState.SetAliveCell(25, 4);
	InitialState.SetAliveCell(25, 8);
	InitialState.SetAliveCell(27, 3);
	InitialState.SetAliveCell(27, 4);
	InitialState.SetAliveCell(27, 8);
	InitialState.SetAliveCell(27, 9);

	InitialState.SetAliveCell(37, 5);
	InitialState.SetAliveCell(38, 5);
	InitialState.SetAliveCell(37, 6);
	InitialState.SetAliveCell(38, 6);

	return std::make_unique<State>(InitialState);
}
