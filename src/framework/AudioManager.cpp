#include "AudioManager.hpp"

ef::AudioManager::AudioManager()
{
	return;
}

int ef::AudioManager::init(ef::ComponentManager* com, ef::AssetManager* am)
{
	this->am = am;
	this->com = com;
	return 0;
}

void ef::AudioManager::playSound(unsigned int entityId)
{
	ef::cp::Sound* s = this->com->getSound(entityId);
	if(s == nullptr)
	{
		std::cout << "sound component not in entity\n";
	}
	else
	{
		s->sound.setBuffer(this->am->getSound(s->soundKey));
		s->sound.play();
	}
	return;
}

void ef::AudioManager::playMusic(unsigned int entityId)
{
	sf::Music m;
	std::string s = this->com->getMusic(entityId)->musicKey;
	
	if(!m.openFromFile(s))
	{
		std::cout << "music component not in entity or file not found\n";
	}
	else
	{
		m.play();
	}
	return;
}