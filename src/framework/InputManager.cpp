#include "InputManager.hpp"

ef::InputManager::InputManager()
{
	return;
}

int ef::InputManager::init(ef::Window* win)
{
	this->win = win;
	return 0;
}

bool ef::InputManager::isKeyPressed(ef::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
}

bool ef::InputManager::isButtonPressed(ef::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed((sf::Mouse::Button)button);
}