#include "ComponentManager.hpp"

ef::ComponentManager::ComponentManager()
{
	this->startAmount = 25;
	return;
}

int ef::ComponentManager::init(ef::AssetManager* am)
{
	this->am = am;

	ef::cp::Transform t;
	ef::cp::Motion m;
	ef::cp::Music mu;
	ef::cp::Sprite s;
	ef::cp::Sound so;

	if(t.init())
	{
		return -1;
	}
	if(m.init())
	{
		return -1;
	}
	if(mu.init())
	{
		return -1;
	}
	if(so.init())
	{
		return -1;
	}
	if(s.init())
	{
		return -1;
	}

	for(int i=0; i<this->startAmount; i++)
	{
		this->transforms.push_back(t);
		this->motions.push_back(m);
		this->musics.push_back(mu);
		this->sounds.push_back(so);
		this->sprites.push_back(s);
	}
	return 0;
}

ef::cp::Transform* ef::ComponentManager::getTransform(unsigned int entityId)
{
	ef::cp::Transform* cp = nullptr;

	for(int i = 0; i<this->transforms.size(); i++)
	{
		if(this->transforms[i].entityID == entityId)
		{
			cp = &this->transforms[i];
			break;
		}
	}

	return cp;
}

ef::cp::Motion* ef::ComponentManager::getMotion(unsigned int entityId)
{
	ef::cp::Motion* cp = nullptr;
	
	for(int i = 0; i<this->motions.size(); i++)
	{
		if(this->motions[i].entityID == entityId)
		{
			cp = &this->motions[i];
			break;
		}
	}

	return cp;
}

ef::cp::Sound* ef::ComponentManager::getSound(unsigned int entityId)
{
	ef::cp::Sound* cp = nullptr;
	
	for(int i = 0; i<this->sounds.size(); i++)
	{
		if(this->sounds[i].entityID == entityId)
		{
			cp = &this->sounds[i];
			break;
		}
	}

	return cp;
}

ef::cp::Sprite* ef::ComponentManager::getSprite(unsigned int entityId)
{
	ef::cp::Sprite* cp = nullptr;

	for(int i = 0; i<this->sprites.size(); i++)
	{
		if(this->sprites[i].entityID == entityId)
		{
			cp = &this->sprites[i];
			break;
		}
	}

	return cp;
}

ef::cp::Music* ef::ComponentManager::getMusic(unsigned int entityId)
{
	ef::cp::Music* cp = nullptr;

	for(int i = 0; i<this->musics.size(); i++)
	{
		if(this->musics[i].entityID == entityId)
		{
			cp = &this->musics[i];
			break;
		}
	}

	return cp;
}

int ef::ComponentManager::removeComponent(unsigned int entityId, ef::cp::compID compId)
{
	switch(compId)
	{
		case ef::cp::TRANSFORM:
		{
			for(int i = 0; i<this->transforms.size(); i++)
			{
				if(this->transforms[i].entityID == entityId)
				{
					ef::cp::Transform t;
					t.init();

					this->transforms.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::cp::MOTION:
		{
			for(int i = 0; i<this->motions.size(); i++)
			{
				if(this->motions[i].entityID == entityId)
				{
					ef::cp::Motion t;
					t.init();

					this->motions.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::cp::MUSIC:
		{
			for(int i = 0; i<this->musics.size(); i++)
			{
				if(this->musics[i].entityID == entityId)
				{
					ef::cp::Music t;
					t.init();

					this->musics.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::cp::SOUND:
		{
			for(int i = 0; i<this->sounds.size(); i++)
			{
				if(this->sounds[i].entityID == entityId)
				{
					ef::cp::Sound t;
					t.init();

					this->sounds.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::cp::SPRITE:
		{
			for(int i = 0; i<this->sprites.size(); i++)
			{
				if(this->sprites[i].entityID == entityId)
				{
					ef::cp::Sprite t;
					t.init();

					this->sprites.at(i) = t;
					break;
				}
			}
			break;
		}
	}

	return 0;
}

void ef::ComponentManager::setSpriteSize(unsigned int entityId, float width, float height)
{
	sf::Vector2u vec = this->am->getTexture(this->getSprite(entityId)->textureKey).getSize();

	ef::cp::Sprite* s = this->getSprite(entityId);
	s->sprite.scale(width/vec.x, height/vec.y);
	return;
}