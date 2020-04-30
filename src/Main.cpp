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

void Benchmark()
{
	long long Sum = 0;

	const int BenchmarkIterationCount = 10;
	const int GenerationEvolutionCount = 10000;
	const int SpaceSize = 32;

	for (int Bench = 0; Bench < BenchmarkIterationCount; Bench++) {
		Generation Generation(*GliderGun::CreateState(), Space(SpaceSize, SpaceSize));

		const std::chrono::milliseconds Start = GetTime();
		for (int Index = 0; Index < GenerationEvolutionCount; Index++) {
			Generation.Evolve();
		}

		const std::chrono::milliseconds TotalTime = GetTime() - Start;
		std::cout << "Completed " << GenerationEvolutionCount << " iterations in " << TotalTime.count() << " milliseconds." << std::endl;

		Sum += TotalTime.count();
	}

	std::cout << "Completed " << BenchmarkIterationCount << " * " << GenerationEvolutionCount << " iterations in an average time of " << Sum / BenchmarkIterationCount << " milliseconds." << std::endl;
}

int main()
{
	Benchmark();
}
