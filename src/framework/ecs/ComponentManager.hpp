#pragma once
#include "Components.hpp"
#include "../AssetManager.hpp"
#include <vector>

#include <iostream>

namespace ef
{
	class ComponentManager
	{
		private:
			// Start amount of components
			unsigned int startAmount;

			ef::AssetManager* am;

			std::vector<ef::cp::Transform> transforms;
			std::vector<ef::cp::Motion> motions;
			std::vector<ef::cp::Music> musics;
			std::vector<ef::cp::Sound> sounds;
			std::vector<ef::cp::Sprite> sprites;

		public:
			/*	ComponentManager Constructor
			*
			*/
			ComponentManager();

			/*	Initialize the Component Manager
			*	@return Returns 0 if succeded
			*/
			int init(ef::AssetManager* am);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::cp::Transform* getTransform(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::cp::Motion* getMotion(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::cp::Sound* getSound(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::cp::Sprite* getSprite(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::cp::Music* getMusic(unsigned int entityId);

			/*	Adds a Component to an Entity
			*	@returns 0 if succeded
			*/
			template<typename T> // template functions must be defined in header
			int addComponent(unsigned int entityId)
			{
				switch(T::compID)
				{
					case ef::cp::TRANSFORM:
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

					case ef::cp::MOTION:
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

					case ef::cp::MUSIC:
					{
						for(int i = 0; i<this->musics.size(); i++)
						{
							if(this->musics[i].entityID == entityId)
							{
								return -1;
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
								return -1;
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
								return -1;
								break;
							}
						}
						break;
					}
					
					default:
						return -1;
						break;
				}

				switch(T::compID)
				{
					case ef::cp::TRANSFORM:
					{
						for(int i = 0; i<this->transforms.size(); i++)
						{
							if(this->transforms[i].entityID == 0)
							{
								this->transforms[i].entityID = entityId;
								break;
							}
							else if(i == this->transforms.size() - 1 && (this->transforms[i].entityID != 0))
							{
								ef::cp::Transform t;
								t.init();
								t.entityID = entityId;
								this->transforms.push_back(t);
								break;
							}
						}
						break;
					}
					
					case ef::cp::MOTION:
					{
						for(int i = 0; i<this->motions.size(); i++)
						{
							if(this->motions[i].entityID == 0)
							{
								this->motions[i].entityID = entityId;
								break;
							}
							else if(i+1 == this->motions.size() && this->motions[i].entityID != 0)
							{
								ef::cp::Motion t;
								t.init();
								t.entityID = entityId;
								this->motions.push_back(t);
							}
						}
						break;
					}

					case ef::cp::MUSIC:
					{
						for(int i = 0; i<this->musics.size(); i++)
						{
							if(this->musics[i].entityID == 0)
							{
								this->musics[i].entityID = entityId;
								break;
							}
							else if(i+1 == this->musics.size() && this->musics[i].entityID != 0)
							{
								ef::cp::Music t;
								t.init();
								t.entityID = entityId;
								this->musics.push_back(t);
							}
						}
						break;
					}

					case ef::cp::SOUND:
					{
						for(int i = 0; i<this->sounds.size(); i++)
						{
							if(this->sounds[i].entityID == 0)
							{
								this->sounds[i].entityID = entityId;
								break;
							}
							else if(i+1 == this->sounds.size() && this->sounds[i].entityID != 0)
							{
								ef::cp::Sound t;
								t.init();
								t.entityID = entityId;
								this->sounds.push_back(t);
							}
						}
						break;
					}

					case ef::cp::SPRITE:
					{
						for(int i = 0; i<this->sprites.size(); i++)
						{
							if(this->sprites[i].entityID == 0)
							{
								this->sprites[i].entityID = entityId;
								break;
							}
							else if(i+1 == this->sprites.size() && this->sprites[i].entityID != 0)
							{
								ef::cp::Sprite t;
								t.init();
								t.entityID = entityId;
								this->sprites.push_back(t);
							}
						}
						break;
					}
				}
				return 0;
			}

			/*	Removes a Component from an Entity
			*	@returns 0 if succeded
			*/
			int removeComponent(unsigned int entityId, ef::cp::compID);

			/*	Sets the size of a sprite
			*
			*/
			void setSpriteSize(unsigned int entityId, float width, float height);
	};
}