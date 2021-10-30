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
	
	if(this->renderer.init(&this->window, &this->componentManager, &this->assetManager)) // Also pass the asset manager too
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

	if(this->componentManager.init(&this->assetManager))
	{
		return -1;
	}
	
	this->assetManager.addTexture("IOTA", "../../src/framework/imgs/iota.png"); //TODO: temp

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
		sf::Clock clock;
		
		std::cout << "Loading Start!\n";

		// Initialize game
		std::cout << "Loading...\n";

		clock.restart();
		while(clock.getElapsedTime().asMilliseconds() < 5000)
		{
			// buffer time to see loading window
		}

		// Set finsihed to true when game is loaded
		finLoad = true;
		std::cout << "Loading Complete!\n";
		return;
	};

	// Create loading window
	ef::Window loadingWin;
	loadingWin.init("Project_Alpha", 800, 600);
	ef::Entity loadImg;
	loadImg.init();

	this->componentManager.addComponent(loadImg.getId(), ef::Components::TRANSFORM);
	this->componentManager.addComponent(loadImg.getId(), ef::Components::SPRITE);

	this->componentManager.getSprite(loadImg.getId())->textureKey = "IOTA";

	this->componentManager.getTransform(loadImg.getId())->x = 200;
	this->componentManager.getTransform(loadImg.getId())->y = 100;
	this->componentManager.setSpriteSize(loadImg.getId(), 400, 400);

	// Init game [thread]
	std::thread init(load);

	// display loading screen while thread is running
	while(!joinedThread)
	{
		loadingWin.pollEvents();
		this->renderer.render(loadImg.getId(), &loadingWin);
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