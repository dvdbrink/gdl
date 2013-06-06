#ifndef DEMO_POSITION_HPP
#define DEMO_POSITION_HPP

#include <gdl/ces/Component.hpp>
#include <gdl/math/Vector3.hpp>

namespace demo
{

struct Position : public gdl::ces::Component<Position>
{
public:
	Position() : Position(0, 0, 0) {}
	Position(float x, float y, float z)
		: current(x, y, z) {}

	gdl::math::Vector3f current;
	gdl::math::Vector3f previous;
};

}

#endif // DEMO_POSITION_HPP
