#include "Framework.hpp"

int main(int argc, char* argv[])
{
	ef::Engine engine;
	if(engine.init())
	{
		return -1;
	}

	// insert game scene creation here

	// pass game to engine

	// engine.gameInit();

	engine.loop();
	return 0;
}