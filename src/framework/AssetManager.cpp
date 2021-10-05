#include "AssetManager.hpp"

ef::AssetManager::AssetManager()
{
	return;
}

int ef::AssetManager::init()
{
	// TODO: make default sound/texture
	// TODO: make engine/framework icon
	return 0;
}

int ef::AssetManager::addTexture(std::string name, std::string path)
{
	// test if name is already in the map
	// add texture to map if name is not in map
	
	if(this->textures.find(name) != this->textures.end())
	{
		//Texture with name already exists
		return -1;
	}
	else
	{
		sf::Texture tex;
		this->textures.insert({name, tex});
		if(!this->textures.at(name).loadFromFile(path))
		{
			//image not found
			std::cout << "Error: Texture file not found!\n";
			this->textures.erase(name); // TODO: replace with replacement texture
			return -1;
		}
		else
		{
			return 0;
		}
		return 0;	
	}
	return 0;
}

int ef::AssetManager::addSound(std::string name, std::string path)
{
	// test if name is already in the map
	// add sound to map if name is not in map
	
	if(this->sounds.find(name) != this->sounds.end())
	{
		// Sound with name already exists
		return -1;
	}
	else
	{
		sf::SoundBuffer sound;
		this->sounds.insert({name, sound});
		if(!this->sounds.at(name).loadFromFile(path))
		{
			// sound not found
			std::cout << "Error: Sound file not found!\n";
			this->sounds.erase(name); // TODO: replace with replacement sound
			return -1;
		}
		else
		{
			return 0;
		}
		return 0;	
	}
	return 0;
}

sf::Texture ef::AssetManager::getTexture(std::string name)
{
	if(this->textures.find(name) != this->textures.end())
	{
		return this->textures.at(name);
	}
	else
	{
		sf::Texture text; // TODO: replace with replacement texture
		return text;
	}
}

sf::SoundBuffer ef::AssetManager::getSound(std::string name)
{
	if(this->sounds.find(name) != this->sounds.end())
	{
		return this->sounds.at(name);
	}
	else
	{
		sf::SoundBuffer sound; // TODO: replace with replacement sound
		return sound;
	}
}