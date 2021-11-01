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
	ef::Components::Sound* s = this->com->getSound(entityId);
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