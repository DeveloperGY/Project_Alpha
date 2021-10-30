#include "ComponentManager.hpp"

ef::ComponentManager::ComponentManager()
{
	this->startAmount = 5;
	return;
}

int ef::ComponentManager::init(ef::AssetManager* am)
{
	this->am = am;

	ef::Components::Transform t;
	ef::Components::Motion m;
	ef::Components::Sprite s;
	if(t.init())
	{
		return -1;
	}
	if(m.init())
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
		this->sprites.push_back(s);
	}
	return 0;
}

ef::Components::Transform* ef::ComponentManager::getTransform(unsigned int entityId)
{
	ef::Components::Transform* cp = nullptr;
	
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

ef::Components::Motion* ef::ComponentManager::getMotion(unsigned int entityId)
{
	ef::Components::Motion* cp = nullptr;
	
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

ef::Components::Sprite* ef::ComponentManager::getSprite(unsigned int entityId)
{
	ef::Components::Sprite* cp = nullptr;
	
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

int ef::ComponentManager::addComponent(unsigned int entityId, ef::Components::compID compId)
{
	switch(compId)
	{
		case ef::Components::TRANSFORM:
		{
			for(int i = 0; i<this->transforms.size(); i++)
			{
				if(this->transforms[i].entityID == entityId)
				{
					return -1;
					break;
				}
			}
			break;
		}

		case ef::Components::MOTION:
		{
			for(int i = 0; i<this->motions.size(); i++)
			{
				if(this->motions[i].entityID == entityId)
				{
					return -1;
					break;
				}
			}
			break;
		}

		case ef::Components::SPRITE:
		{
			for(int i = 0; i<this->sprites.size(); i++)
			{
				if(this->sprites[i].entityID == entityId)
				{
					return -1;
					break;
				}
			}
			break;
		}
	}

	switch(compId)
	{
		case ef::Components::TRANSFORM:
		{
			for(int i = 0; i<this->transforms.size(); i++)
			{
				if(this->transforms[i].entityID == 0)
				{
					this->transforms[i].entityID == entityId;
					break;
				}
			}

			ef::Components::Transform t;
			t.init();
			t.entityID = entityId;
			this->transforms.push_back(t);

			break;
		}
		
		case ef::Components::MOTION:
		{
			for(int i = 0; i<this->motions.size(); i++)
			{
				if(this->motions[i].entityID == 0)
				{
					this->motions[i].entityID == entityId;
					break;
				}
			}

			ef::Components::Motion t;
			t.init();
			t.entityID = entityId;
			this->motions.push_back(t);

			break;
		}

		case ef::Components::SPRITE:
		{
			for(int i = 0; i<this->sprites.size(); i++)
			{
				if(this->sprites[i].entityID == 0)
				{
					this->sprites[i].entityID == entityId;
					break;
				}
			}

			ef::Components::Sprite t;
			t.init();
			t.entityID = entityId;
			this->sprites.push_back(t);

			break;
		}
	}

	return 0;
}

int ef::ComponentManager::removeComponent(unsigned int entityId, ef::Components::compID compId)
{
	switch(compId)
	{
		case ef::Components::TRANSFORM:
		{
			for(int i = 0; i<this->transforms.size(); i++)
			{
				if(this->transforms[i].entityID == entityId)
				{
					ef::Components::Transform t;
					t.init();

					this->transforms.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::Components::MOTION:
		{
			for(int i = 0; i<this->motions.size(); i++)
			{
				if(this->motions[i].entityID == entityId)
				{
					ef::Components::Motion t;
					t.init();

					this->motions.at(i) = t;
					break;
				}
			}
			break;
		}

		case ef::Components::SPRITE:
		{
			for(int i = 0; i<this->sprites.size(); i++)
			{
				if(this->sprites[i].entityID == entityId)
				{
					ef::Components::Sprite t;
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

	ef::Components::Sprite* s = this->getSprite(entityId);
	s->sprite.scale(width/vec.x, height/vec.y);
	return;
}