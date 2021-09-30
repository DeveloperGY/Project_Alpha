#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>

namespace ef
{
	/* 	Asset Manager
	*	Manages textures and sound
	*/
	class AssetManager
	{
	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Sound> sounds;
	public:
		/*	Asset Manager Constructor
		*
		*/
		AssetManager();

		/* 	Initializes the Asset Manager
		*	@return Returns 0 if succeeded
		*/
		int init();
	};
}