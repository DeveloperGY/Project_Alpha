#pragma once
#include <SFML/Graphics.hpp>

#include <string>

namespace ef
{
	class Window
	{
	private:

		sf::RenderWindow window;

		int width;
		int height;
		std::string title;

	public:

		/* Constructor
		*
		*/
		Window();

		/* 	Initializes the Window Object
		*	@return Returns 0 if succeeded
		*/
		int init(int width = 1440, int height = 960, std::string title = "Window");
		
		/*	Updates the Window Object
		*	@return Returns 0 if succeeded
		*/
		int update();

		// Getters/Setters

		/* 	Sets the Window Title
		*	
		*/
		void setTitle(std::string title);

		/* 	Sets the Window Dimensions
		*	If a parameter is set to 0, it will stay as is.
		*/
		void setDimensions(int width, int height);
	};
}