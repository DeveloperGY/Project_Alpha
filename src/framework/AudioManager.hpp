#pragma once
#include "AssetManager.hpp"
#include "ECS.hpp"

namespace ef
{
	class AudioManager
	{
		private:
			ef::ComponentManager* com;
			ef::AssetManager* am;

		public:
			/*	AudioManager Constructor
			*
			*/
			AudioManager();

			/*	Initializes the AudioManager
			*	@return Returns 0 if succeded
			*/
			int init(ef::ComponentManager*, ef::AssetManager*);

			void play(unsigned int entityId);
	};
}