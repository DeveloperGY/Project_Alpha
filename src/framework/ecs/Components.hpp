#pragma once

namespace ef
{
	namespace Components
	{
		// Virtual struct to inherit from
		struct Component{};

		struct Transform: public Component
		{
			float x;
			float y;
		};
	}
}