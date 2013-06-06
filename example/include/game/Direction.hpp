#ifndef DEMO_DIRECTION_HPP
#define DEMO_DIRECTION_HPP

#include <gdl/ces/Component.hpp>
#include <gdl/math/Vector3.hpp>

namespace demo
{

struct Direction : public gdl::ces::Component<Direction>
{
public:
	Direction() : Direction(0, 0, 0) {}
	Direction(float x, float y, float z)
		: current(x, y, z) {}

	gdl::math::Vector3f current;
	gdl::math::Vector3f previous;
};

}

#endif // DEMO_DIRECTION_HPP
