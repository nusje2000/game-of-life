#pragma once

class Cell
{
public:
	Cell(int X, int Y);
	
	int GetX() const;

	int GetY() const;

private:
	int X;

	int Y;
};
