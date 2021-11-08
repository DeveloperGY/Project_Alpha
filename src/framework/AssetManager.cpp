#include "AssetManager.hpp"

ef::AssetManager::AssetManager()
{
	return;
}

int ef::AssetManager::init()
{
	sf::Image img;
	img.create(2,2);

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			if((i >= 1 && j >= 1) || ((i < 1 && j < 1)))
			{
				img.setPixel(j, i, sf::Color(0, 0, 0));
			}
			else
			{
				img.setPixel(j, i, sf::Color(255, 0, 255, 255));
			}
		}
	}

	sf::Texture tex;
	tex.loadFromImage(img);
	this->textures.insert({"~r", tex});

	sf::Color clear(0, 0, 0, 0);
	sf::Color blue(0x5F, 0xCD, 0xE4);
	sf::Color black(0x000000);
	sf::Color lRed(255, 0, 0);
	sf::Color dRed(0x78, 0, 0);

	sf::Image image;
	image.create(14, 14);

	sf::Color arr[14][14] = {
		{clear, clear, black, black, black, black, black, black, black, black, black, black, clear, clear},
		{clear, black, blue , blue , blue , blue , blue , blue , blue , blue , blue , blue , black, clear},
		{clear, black, blue , black, black, black, black, black, black, black, black, blue , black, clear},
		{black, blue , blue , blue , blue , black, black, black, black, blue , blue , blue , blue , black},
		{black, blue , blue , blue , black, lRed , dRed , dRed , lRed , black, blue , blue , blue , black},
		{black, blue , blue , black, lRed , lRed , dRed , dRed , lRed , lRed , black, blue , blue , black},
		{black, blue , blue , black, lRed , lRed , black, black, lRed , lRed , black, blue , blue , black},
		{black, blue , blue , black, lRed , lRed , black, black, lRed , lRed , black, blue , blue , black},
		{black, blue , blue , black, lRed , lRed , dRed , dRed , lRed , lRed , black, blue , blue , black},
		{black, blue , blue , blue , black, lRed , dRed , dRed , lRed , black, blue , blue , blue , black},
		{black, blue , blue , blue , blue , black, black, black, black, blue , blue , blue , blue , black},
		{clear, black, blue , black, black, black, black, black, black, black, black, blue , black, clear},
		{clear, black, blue , blue , blue , blue , blue , blue , blue , blue , blue , blue , black, clear},
		{clear, clear, black, black, black, black, black, black, black, black, black, black, clear, clear},
	};
	
	for(int i=0; i<14; i++)
	{
		for(int j=0; j<14; j++)
		{
			image.setPixel(j, i, arr[i][j]);
		}
	}

	sf::Texture texture;
	texture.loadFromImage(image);
	this->textures.insert({"~e", texture});

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
			this->textures.at(name) = this->textures.at("~r");
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

int ef::AssetManager::addMusic(std::string name, std::string path)
{
	// test if name is already in the map
	// add music to map if name is not in map
	
	if(this->music.find(name) != this->music.end())
	{
		// Music with name already exists
		return -1;
	}
	else
	{
		this->music.insert({name, path});
		
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
		return this->textures.at("~r");
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
		sf::SoundBuffer sound;
		return sound;
	}
}

std::string ef::AssetManager::getMusic(std::string name)
{
	if(this->music.find(name) != this->music.end())
	{
		return this->music.at(name);
	}
	else
	{
		return "";
	}
}