#pragma once
#include "AssetManager.hpp"
#include "ecs/ECS.hpp"

namespace ef
{
	class AudioManager
	{
		private:
			ef::ComponentManager* com;
			ef::AssetManager* am;

		public:
			/*	Audio Manager Constructor
			*
			*/
			AudioManager();

			/*	Initializes the Audio Manager
			*	@return Returns 0 if succeded
			*/
			int init(ef::ComponentManager*, ef::AssetManager*);

			void playSound(unsigned int entityId);

			void playMusic(unsigned int entityId);
	};
}