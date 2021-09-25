#pragma once
#include "Window.hpp"
#include "Renderer.hpp"

namespace ef
{
	class Engine
	{
	private:
		ef::Window window;
		ef::Renderer renderer;

		bool running;

	public:

		/* Constructor
		*
		*/
		Engine();

		/*	Initializes the Engine
		*	@return Returns 0 if succeeded
		*/
		int init();

		/* 	Game Loop
		*
		*/
		void loop();
	};
}