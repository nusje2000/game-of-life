#include "Cell.h"

Cell::Cell(const int X, const int Y): X(X), Y(Y)
{
}

int Cell::GetX() const
{
	return X;
}

int Cell::GetY() const
{
	return Y;
}
