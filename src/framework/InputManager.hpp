#pragma once
#include "Window.hpp"

namespace ef
{
	/*	Input Manager Class
	*	Manages Window Inputs
	*/
	class InputManager
	{
	private:
		ef::Window* win;

	public:
		/* 	Constructor
		*
		*/
		InputManager();

		/* 	Initializes the Input Manager
		*	@return Returns 0 if suceeded
		*/
		int init(ef::Window* win);
	};
}