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

	//TODO: Make loading window appear (use a thread to init the game)

	// engine.gameInit();

	//TODO: Make Loading window close

	engine.loop();
	return 0;
}