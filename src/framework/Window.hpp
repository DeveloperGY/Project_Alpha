#pragma once
#include <SFML/Graphics.hpp>

#include <string>

namespace ef
{
	/*	Window Class
	*
	*/
	class Window
	{
	private:

		sf::RenderWindow window;

		int width;
		int height;
		std::string title;

	public:

		/* 	Constructor
		*
		*/
		Window();

		/* 	Initializes the Window Object
		*	@return Returns 0 if succeeded
		*/
		int init(std::string title = "Window", int width = 1440, int height = 960, bool loading = false);

		/* 	Polls the Window Events
		* 	Handles all window based events
		*/
		void pollEvents();

		/*	Displays the Window
		*
		*/
		void display();


	// 	Getters/Setters

		/* 	Sets the Window Title
		*	
		*/
		void setTitle(std::string title);

		/* 	Sets the Window Dimensions
		*	If a parameter is set to 0, it will stay as is.
		*/
		void setDimensions(int width, int height);

		/*	Tells whether or not the window is open
		*	@return Returns True if the window is open
		*/
		bool isOpen();

		/* Closes the Window
		*
		*/
		void close();

		/* Draws a sprite
		*
		*/
		void draw(sf::Sprite sprite);

		/*	Clears the window with a specified color
		*
		*/
		void clear(float r, float g, float b);
	};
}