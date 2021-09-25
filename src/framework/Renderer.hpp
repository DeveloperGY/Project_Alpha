#pragma once
#include "Window.hpp"

namespace ef
{
	class Renderer
	{
	private:
		ef::Window* window;
	public:
		Renderer();

		/* Initializes Renderer
		*	@return Returns 0 if it succeeded
		*/
		int init(ef::Window* win);
	};
}