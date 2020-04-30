#pragma once

#include <memory>
#include "../State.h"

class GliderGun
{
public:
	static std::unique_ptr<State> CreateState();
};

