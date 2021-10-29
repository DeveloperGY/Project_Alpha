#pragma once
#include "Components.hpp"
#include <vector>

namespace ef
{
	class ComponentManager
	{
		private:
			// Start amount of components
			unsigned int startAmount;

			std::vector<ef::Components::Transform> transforms;
			std::vector<ef::Components::Motion> motions;

		public:
			/*	ComponentManager Constructor
			*
			*/
			ComponentManager();

			/*	Initialize the Component Manager
			*	@return Returns 0 if succeded
			*/
			int init();

			/*	Returns the specified component of an entity
			*	@return returns Component or if component doesnt exist returns nullptr
			*/
			ef::Components::Component* getComponent(unsigned int entityId, ef::Components::compID);

			/*	Adds a Component to an Entity
			*	@returns 0 if succeded
			*/
			int addComponent(unsigned int entityId, ef::Components::compID);

			/*	Removes a Component from an Entity
			*	@returns 0 if succeded
			*/
			int removeComponent(unsigned int entityId, ef::Components::compID);
	};
}