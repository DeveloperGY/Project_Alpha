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

			std::vector<ef::Components::Transform> transforms;
			std::vector<ef::Components::Motion> motions;
			std::vector<ef::Components::Sound> sounds;
			std::vector<ef::Components::Sprite> sprites;

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
			ef::Components::Transform* getTransform(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::Components::Motion* getMotion(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::Components::Sound* getSound(unsigned int entityId);

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::Components::Sprite* getSprite(unsigned int entityId);

			/*	Adds a Component to an Entity
			*	@returns 0 if succeded
			*/
			int addComponent(unsigned int entityId, ef::Components::compID);

			/*	Removes a Component from an Entity
			*	@returns 0 if succeded
			*/
			int removeComponent(unsigned int entityId, ef::Components::compID);

			/*	Sets the size of a sprite
			*
			*/
			void setSpriteSize(unsigned int entityId, float width, float height);
	};
}