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

void ef::Engine::loop()
{
	while(this->running)
	{
		this->running = false; // temporary
	}
	return;
}