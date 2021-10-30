#include "Window.hpp"

ef::Window::Window()
{
	return;
}

int ef::Window::init(std::string title, int width, int height)
{
	this->width = width;
	this->height = height;
	this->title = title;

	this->window.create(sf::VideoMode(this->width, this->height), this->title, sf::Style::Close | sf::Style::Titlebar);

	return 0;
}

void ef::Window::pollEvents()
{
	sf::Event ev;
	while(this->window.pollEvent(ev))
	{
		if(ev.type == sf::Event::Closed)
		{
			this->window.close();
		}
	}
	return;
}

void ef::Window::display()
{
	this->window.display();
	return;
}

void ef::Window::setTitle(std::string title)
{
	this->title = title;
	this->window.setTitle(this->title);
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

	this->window.setSize(sf::Vector2u(this->width, this->height));

	return;
}

bool ef::Window::isOpen()
{
	return this->window.isOpen();
}

void ef::Window::close()
{
	this->window.close();
	return;
}

void ef::Window::draw(sf::Sprite sprite)
{
	this->window.draw(sprite);
	return;
}