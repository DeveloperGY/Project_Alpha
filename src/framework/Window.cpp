#include "Window.hpp"

ef::Window::Window()
{
	return;
}

int ef::Window::init(int width, int height, std::string title)
{
	this->width = width;
	this->height = height;
	this->title = title;

	this->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

	return 0;
}

int ef::Window::update()
{
	this->window.setSize(sf::Vector2u(this->width, this->height));
	this->window.setTitle(this->title);
	return 0;
}

void ef::Window::setTitle(std::string title)
{
	this->title = title;
	return;
}

void ef::Window::setDimensions(int width, int height)
{
	if(width != 0)
	{
		this->width = width;
	}

	if(height != 0)
	{
		this->height = height;
	}

	return;
}