#include "Generation.h"
#include "InitialState/GliderGun.h"
#include "Renderer.h"
#include "Space.h"

int main()
{
	const Space InitialSpace(45, 45);
	Generation CurrentGeneration(GliderGun::CreateState(), InitialSpace);

	do {
		Renderer::Render(CurrentGeneration);
		CurrentGeneration.Evolve();
	} while (true);
}
