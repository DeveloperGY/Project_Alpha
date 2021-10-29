#include "ComponentManager.hpp"

ef::ComponentManager::ComponentManager()
{
	this->startAmount = 5;
	return;
}

int ef::ComponentManager::init()
{
	ef::Components::Transform t;
	ef::Components::Motion m;
	if(t.init())
	{
		return -1;
	}
	if(m.init())
	{
		return -1;
	}

	for(int i=0; i<this->startAmount; i++)
	{
		this->transforms.push_back(t);
		this->motions.push_back(m);
	}
	return 0;
}

ef::Components::Component* ef::ComponentManager::getComponent(unsigned int entityId, ef::Components::compID compId)
{
	ef::Components::Component* cp = nullptr;
	
	switch(compId)
	{
		case ef::Components::TRANSFORM:
		{
			for(int i = 0; i<this->transforms.size(); i++)
			{
				if(this->transforms[i].entityID == entityId)
				{
					cp = &this->transforms[i];
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
					cp = &this->motions[i];
					break;
				}
			}
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
	}

	return 0;
}