#include <chrono>
#include <ctime>
#include <iostream>
#include "Generation.h"
#include "InitialState/GliderGun.h"
#include "Renderer.h"
#include "Space.h"

std::chrono::milliseconds GetTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	);
}

void Run(Generation& Generation)
{
	do {
		Renderer::Render(Generation);
		Generation.Evolve();
	} while (true);
}

void Benchmark(Generation& Generation)
{
	const std::chrono::milliseconds Start = GetTime();

	for (int Index = 0; Index < 10000; Index++) {
		Generation.Evolve();
	}
	const std::chrono::milliseconds TotalTime = GetTime() - Start;

	std::cout << "Completed 1000 iterations in " << TotalTime.count() << " milliseconds.";
}

int main()
{
	const Space InitialSpace(45, 45);
	Generation InitialGeneration(*GliderGun::CreateState(), InitialSpace);

	Benchmark(InitialGeneration);
}
