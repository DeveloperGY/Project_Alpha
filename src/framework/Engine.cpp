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