#pragma once

#include <memory>
#include <vector>

class State
{
public:
	const std::vector<unsigned int>& GetCells() const;

	int GetNeighboursCountByPosition(unsigned int Index) const;

	std::unique_ptr<std::vector<unsigned int>> GetNeighboursIndexesByPosition(const unsigned int Index) const;

	bool PositionIsAliveCell(const unsigned short X, const unsigned short Y) const;

	bool PositionIsAliveCell(const unsigned int Index) const;

	void SetAliveCell(const unsigned short X, const unsigned short Y);

	void SetAliveCell(const unsigned int Index);

	void Sort();

	unsigned short GetXFromIndex(const unsigned int Index) const;

	unsigned short GetYFromIndex(const unsigned int Index) const;

	int CreateIndex(const unsigned short X, const unsigned short Y) const;

private:
	std::vector<unsigned int> Cells;
};
