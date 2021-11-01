#pragma once
#include "Entity.hpp"
#include <vector>

namespace ef
{
	class Scene
	{
		private:
			std::vector<ef::Entity> entities;
			unsigned int id;

		public:
			/*	Scene Constructor
			*
			*/
			Scene();

			/*	Initialize Scene
			*	@return returns 0 if succeded
			*/
			int init(unsigned int id);

			/*	Get Scene ID
			*	@return unsigned int Scene ID
			*/
			unsigned int getId();
	};
}