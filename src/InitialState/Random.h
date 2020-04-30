#pragma once

#include "../Space.h"
#include "../State.h"

class Random
{
public:
	static State CreateState(const Space Space, const int AliveProbability);
};
