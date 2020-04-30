#pragma once

#include "Space.h"
#include "State.h"

class Generation
{
public:
	Generation(State State, Space Space);

	const State& GetState() const;

	const Space& GetSpace() const;

	int GetGenerationId() const;

	void Evolve();

private:
	State CurrentState;
	Space Space;
	int GenerationId;

	bool IsAliveCellInNextGeneration(const unsigned int Index) const;
};
