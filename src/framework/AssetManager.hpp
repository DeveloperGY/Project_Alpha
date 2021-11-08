#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

namespace ef
{
	/* 	Asset Manager
	*	Manages textures and sound
	*/
	class AssetManager
	{
	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::SoundBuffer> sounds;
		std::map<std::string, std::string> music;

	public:
		/*	Asset Manager Constructor
		*
		*/
		AssetManager();

		/* 	Initializes the Asset Manager
		*	@return Returns 0 if succeeded
		*/
		int init();

		/* 	Loads an Image File into the Asset Manager. 
		*	Be sure to set the path relative to the executable
		*	@return Returns 0 if succeded
		*/
		int addTexture(std::string name, std::string path);

		/* 	Loads a Sound File into the Asset Manager. 
		*	Be sure to set the path relative to the executable
		*	@return Returns 0 if succeded
		*/
		int addSound(std::string, std::string);

		/* 	Loads a Music File into the Asset Manager. 
		*	Be sure to set the path relative to the executable
		*	@return Returns 0 if succeded
		*/
		int addMusic(std::string, std::string);

		// int addMusic(std::string name, std::string path);

		/*	Gets a texture from the texture map
		*	@return returns a texture if found or the replacement texture if not
		*/
		sf::Texture getTexture(std::string);

		/*	Gets a sound buffer from the sound map
		*	@return returns a sound buffer if found or the replacement sound buffer if not
		*/
		sf::SoundBuffer getSound(std::string);

		/*	Gets music from the music map
		*	@return returns a music pointer if found or nullptr if not
		*/
		std::string getMusic(std::string);
	};
}