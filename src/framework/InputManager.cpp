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