#pragma once

#include <memory>
#include <vector>
#include "Cell.h"

class State
{
public:
	State(std::shared_ptr<std::vector<Cell>> Cells);
	
	std::shared_ptr<std::vector<Cell>> GetNeighboursByPosition(const int X, const int Y) const;

	bool PositionIsAliveCell(const int X, const int Y) const;
	
private:
	std::shared_ptr<std::vector<Cell>> Cells;
};
