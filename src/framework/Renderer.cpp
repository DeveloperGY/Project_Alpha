#include "Renderer.hpp"

ef::Renderer::Renderer()
{
	return;
}

int ef::Renderer::init(ef::Window* win)
{
	this->window = win;
	return 0;
}