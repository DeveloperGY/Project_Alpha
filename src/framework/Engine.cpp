#include "Engine.hpp"

ef::Engine::Engine()
{
	this->window.init();
	this->renderer.init(&this->window);
	this->running = false;
}

int ef::Engine::init()
{
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



		this->window.display();

		if(!this->window.isOpen())
		{
			this->exit();
		}
	}
	return;
}