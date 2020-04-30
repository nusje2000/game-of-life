#include "Space.h"

Space::Space(const int Width, const int Height): Width(Width), Height(Height)
{
}

int Space::GetWidth() const
{
	return Width;
}

int Space::GetHeight() const
{
	return Height;
}
