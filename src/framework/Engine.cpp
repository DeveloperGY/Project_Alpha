#include "Engine.hpp"

ef::Engine::Engine()
{
	this->running = false;
	return;
}

int ef::Engine::init()
{
	if(this->window.init())
	{
		return -1;
	}

	if(this->renderer.init(&this->window))
	{
		return -1;
	}

	if(this->inputManager.init(&this->window))
	{
		return -1;
	}

	this->running = true;
	return 0;
}

int ef::Engine::exit()
{
	this->running = false;
	return 0;
}

void ef::Engine::loop()
{
	// Initialize Game
	this->initGame();

	// Start Loop
	while(this->running)
	{
		this->window.pollEvents();

		// Handle Game

		this->window.display();

		if(!this->window.isOpen())
		{
			this->exit();
		}
	}
	return;
}

void ef::Engine::initGame()
{
	// Lambda func for thread
	auto load = [] () -> void
	{
		// Initialize game
		for(int i=0;i<10000;i++)
		{
			std::cout << "Loading...\n";
		}
		return;
	};

	// Create loading window
	ef::Window loadingWin;
	loadingWin.init("Project_Alpha", 800, 600);
	std::cout << "Loading Start!\n";
	
	// Init game [thread]
	std::thread init(load);

	// display loading screen
	loadingWin.display();
	init.join();
	std::cout << "Loading Complete!\n";
	loadingWin.close();
	return;
}