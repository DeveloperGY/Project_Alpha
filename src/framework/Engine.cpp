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

		this->window.clear(0, 0, 0);

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
		std::cout << "Loading Complete!\n";
		finLoad = true;
		return;
	};

	// Create loading window
	ef::Window loadingWin;
	loadingWin.init("Project_Alpha", 800, 600, true);
	ef::Entity loadImg;
	loadImg.init();

	this->componentManager.addComponent(loadImg.getId(), ef::Components::TRANSFORM);
	this->componentManager.addComponent(loadImg.getId(), ef::Components::SPRITE);

	ef::Components::Sprite* sp = this->componentManager.getSprite(loadImg.getId());
	ef::Components::Transform* tr = this->componentManager.getTransform(loadImg.getId());

	if(sp == nullptr)
	{
		std::cout << "sp is nullptr\n";
	}
	else
	{
		sp->textureKey = "IOTA";
	}

	if(tr == nullptr)
	{
		std::cout << "tr is nullptr\n";
	}
	else
	{
		tr->x = 200;
		tr->y = 100;
	}

	this->componentManager.setSpriteSize(loadImg.getId(), 400, 400);;

	// Init game [thread]
	std::thread init(load);

	// display loading screen while thread is running
	while(!joinedThread)
	{
		loadingWin.pollEvents();
		loadingWin.clear(0, 0, 0);
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