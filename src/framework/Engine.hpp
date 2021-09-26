#pragma once
#include "Window.hpp"
#include "Renderer.hpp"

namespace ef
{
	/*	Game Engine Class
	*
	*/
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

		/*	Exits the game and cleans up the engine
		*	@return Returns 0 if succeeded
		*/
		int exit();

		/* 	Game Loop
		*
		*/
		void loop();
	};
}