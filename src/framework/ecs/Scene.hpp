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
			Scene();

			int init(unsigned int id);

			unsigned int getId();
	};
}