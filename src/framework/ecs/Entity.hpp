#pragma once
#include "ComponentManager.hpp"

namespace ef
{
	class Entity
	{
		private:
			// Entity ID
			unsigned int id;

		public:
			/*	Entity Constructor
			*
			*/
			Entity();

			/*	Initializes the Entity
			*	@return returns 0 if succeded
			*/
			int init(unsigned int id);

			/*	Returns the Entity ID
			*	@return unsigned int Entity ID
			*/
			unsigned int getId();

			/* Defined behaviour for the entity
			*
			*/
			virtual void behaviour() = 0;
	};
}