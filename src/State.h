#pragma once

#include <map>
#include <vector>

class State
{
public:
	int GetNeighboursCountByPosition(const unsigned short X, const unsigned short Y) const;

	bool PositionIsAliveCell(const unsigned short X, const unsigned short Y) const;

	void SetAliveCell(const unsigned short X, const unsigned short Y);

	void Sort();
	
private:
	std::vector<unsigned int> Cells;

	int CreateIndex(const unsigned short X, const unsigned short Y) const;
};
