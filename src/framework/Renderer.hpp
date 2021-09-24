#pragma once
#include <SFML/Graphics.hpp>

#include <string>

namespace ef
{
	class Renderer
	{
	private:
		sf::RenderWindow window;

		int width;
		int height;
		std::string title;

	public:
		// Renderer Constructor
		Renderer();

		/* 	Renderer Initializer
		*	@return Returns 0 if it succeedes
		*/
		int init();

		void render(); // Does NOT take an Entity, takes the parts of the entity required for rendering
	};
}