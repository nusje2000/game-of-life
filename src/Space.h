#pragma once

class Space
{
public:
	Space(const int Width, const int Height);

	int GetWidth() const;
	int GetHeight() const;

private:
	const int Width;
	const int Height;
};
