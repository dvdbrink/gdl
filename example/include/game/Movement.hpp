#ifndef DEMO_MOVEMENT_HPP
#define DEMO_MOVEMENT_HPP

#include <gdl/ces/System.hpp>
#include <gdl/ces/Entity.hpp>

namespace demo
{

class Movement : public gdl::ces::System
{
public:
	Movement();
	void update(gdl::ces::Entity::Ptr, double) override;
};

}

#endif // DEMO_MOVEMENT_HPP
