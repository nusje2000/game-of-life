#pragma once

#include <memory>

#include "../Space.h"
#include "../State.h"

class Random
{
public:
	static std::unique_ptr<State> CreateState(const Space Space, const int AliveProbability);
};
