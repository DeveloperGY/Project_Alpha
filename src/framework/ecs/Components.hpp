#pragma once
#include "../Utility.hpp"

namespace ef
{
	namespace Components
	{
		// enum of types of components
		enum compID
		{
			COMPONENT,
			TRANSFORM,
			MOTION,
		};

		// Virtual struct to inherit from
		struct Component
		{
			unsigned int entityID;
			
			/* Initialize the Component
			*	@return Returns 0 if succeded
			*/
			virtual int init()
			{
				this->entityID = 0;
				return 0;
			}
		};

		struct Transform: public Component
		{
			float x;
			float y;

			/* Initialize the Component
			*	@return Returns 0 if succeded
			*/
			int init()
			{
				this->entityID = 0;
				this->x = 0;
				this->y = 0;
				return 0;
			}
		};

		struct Motion: public Component
		{
			ef::Vec2 velocity;
			ef::Vec2 acceleration;

			int init()
			{
				this->velocity.x = 0;
				this->velocity.y = 0;
				this->acceleration.x = 0;
				this->acceleration.y = 0;
				this->entityID = 0;
				return 0;
			}
		};
	}
}