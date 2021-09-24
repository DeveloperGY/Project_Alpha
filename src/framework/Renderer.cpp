#include "Renderer.hpp"

ef::Renderer::Renderer()
{
	this->width = 1440;
	this->height = 960;
	this->title = "Window";
	return;
}

int ef::Renderer::init()
{
	// TODO: Create default texture in here

	this->window.create(sf::VideoMode(this->width, this->height), this->title, sf::Style::Close | sf::Style::Titlebar);
	return 0;
}

int ef::Renderer::update()
{
	this->window.setTitle(this->title);
}

// Getters / Setters

void ef::Renderer::setTitle(std::string title)
{
	this->title = title;
	return;
}