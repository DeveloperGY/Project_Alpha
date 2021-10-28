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
	
	if(this->renderer.init(&this->window)) // Also pass the asset manager too
	{
		return -1;
	}

	if(this->inputManager.init(&this->window))
	{
		return -1;
	}

	if(this->assetManager.init())
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
	bool finLoad = false;
	bool joinedThread = false;

	// Lambda func for thread
	auto load = [&finLoad] () -> void
	{
		std::cout << "Loading Start!\n";

		// Initialize game
		std::cout << "Loading...\n";

		// Set finsihed to true when game is loaded
		finLoad = true;
		std::cout << "Loading Complete!\n";
		return;
	};

	// Create loading window
	ef::Window loadingWin;
	loadingWin.init("Project_Alpha", 800, 600);
	
	// Init game [thread]
	std::thread init(load);

	// display loading screen while thread is running
	while(!joinedThread)
	{
		loadingWin.pollEvents();
		loadingWin.display();

		if(finLoad)
		{
			init.join();
			joinedThread = true;
		}
	}

	loadingWin.close();
	return;
}