#include "Components.hpp"

namespace ef
{
	class Entity
	{
		private:
			unsigned int id;

		public:
			Entity();

			int init(unsigned int id);

			unsigned int getId();
	};
}