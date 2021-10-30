#pragma once
#include "Window.hpp"
#include "Renderer.hpp"
#include "InputManager.hpp"
#include "AssetManager.hpp"
#include "ecs/ECS.hpp"

#include <thread>
#include <iostream>

/*	TODO:
	Engine Icon in Asset Manager
	Audio Player
	Physics Engine
	ECS
*/

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
		ef::InputManager inputManager;
		ef::AssetManager assetManager;
		ef::ComponentManager componentManager;

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

		/*	Initializes the game with a loading window
		*
		*/
		void initGame();

		/* 	Game Loop
		*
		*/
		void loop();
	};
}