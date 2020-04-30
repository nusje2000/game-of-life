#include "GliderGun.h"
#include "../Cell.h"

State GliderGun::CreateState()
{
	std::vector<Cell> InitialCells;
	InitialCells.emplace_back(Cell(3, 7));
	InitialCells.emplace_back(Cell(4, 7));
	InitialCells.emplace_back(Cell(3, 8));
	InitialCells.emplace_back(Cell(4, 8));

	InitialCells.emplace_back(Cell(13, 7));
	InitialCells.emplace_back(Cell(13, 8));
	InitialCells.emplace_back(Cell(13, 9));
	InitialCells.emplace_back(Cell(14, 6));
	InitialCells.emplace_back(Cell(14, 10));
	InitialCells.emplace_back(Cell(15, 5));
	InitialCells.emplace_back(Cell(15, 11));
	InitialCells.emplace_back(Cell(16, 5));
	InitialCells.emplace_back(Cell(16, 11));
	InitialCells.emplace_back(Cell(17, 8));
	InitialCells.emplace_back(Cell(18, 6));
	InitialCells.emplace_back(Cell(18, 10));
	InitialCells.emplace_back(Cell(19, 7));
	InitialCells.emplace_back(Cell(19, 8));
	InitialCells.emplace_back(Cell(19, 9));
	InitialCells.emplace_back(Cell(20, 8));

	InitialCells.emplace_back(Cell(23, 5));
	InitialCells.emplace_back(Cell(23, 6));
	InitialCells.emplace_back(Cell(23, 7));
	InitialCells.emplace_back(Cell(24, 5));
	InitialCells.emplace_back(Cell(24, 6));
	InitialCells.emplace_back(Cell(24, 7));
	InitialCells.emplace_back(Cell(25, 4));
	InitialCells.emplace_back(Cell(25, 8));
	InitialCells.emplace_back(Cell(27, 3));
	InitialCells.emplace_back(Cell(27, 4));
	InitialCells.emplace_back(Cell(27, 8));
	InitialCells.emplace_back(Cell(27, 9));

	InitialCells.emplace_back(Cell(37, 5));
	InitialCells.emplace_back(Cell(38, 5));
	InitialCells.emplace_back(Cell(37, 6));
	InitialCells.emplace_back(Cell(38, 6));

	return State(std::make_shared<std::vector<Cell>>(InitialCells));
}
