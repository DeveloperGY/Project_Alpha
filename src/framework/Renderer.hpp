#pragma once
#include "Window.hpp"
#include "./ecs/ECS.hpp"
#include "AssetManager.hpp"

namespace ef
{
	/*	Renderer Class
	*
	*/
	class Renderer
	{
	private:
		ef::Window* window;
		ef::ComponentManager* componentManager;
		ef::AssetManager* assetManager;
		
	public:
		Renderer();

		/* Initializes Renderer
		*	@return Returns 0 if it succeeded
		*/
		int init(ef::Window* win, ef::ComponentManager* com, ef::AssetManager* as);

		/*	Render Entity
		*	@return Returns 0 if it succeded
		*/
		int render(unsigned int entityId, ef::Window* win = nullptr);
	};
}