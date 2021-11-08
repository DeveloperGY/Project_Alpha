#pragma once
#include "../Utility.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace ef
{
	namespace cp
	{
		// enum of types of components
		enum compID
		{
			COMPONENT,
			TRANSFORM,
			MOTION,
			MUSIC,
			SOUND,
			SPRITE,
			ANIMATED_SPRITE,
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

			static unsigned int compID;

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

			static unsigned int compID;

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

		struct Sprite: public Component
		{
			std::string textureKey;
			sf::Sprite sprite;

			static unsigned int compID;

			int init()
			{
				this->textureKey = "";
				this->entityID = 0;
				return 0;
			}
		};

		struct AnimatedSprite: public Component
		{
			std::string textureKey;
			sf::Sprite sprite;
			ef::Vec2 frameDim;
			int animations;

			static unsigned int compID;

			// void changeFrame();
			// void changeAnim();
			sf::Clock clock;

			int init()
			{
				this->textureKey = "";
				this->entityID = 0;
				this->animations = 0;
				this->frameDim.x = 0;
				this->frameDim.y = 0;
				return 0;
			}
		};

		struct Sound: public Component
		{
			sf::Sound sound;
			std::string soundKey;

			static unsigned int compID;

			int init()
			{
				this->entityID = 0;
				return 0;
			}
		};

		struct Music: public Component
		{

			std::string musicKey;

			static unsigned int compID;

			int init()
			{
				this->entityID = 0;
				return 0;
			}
		};
	}
}