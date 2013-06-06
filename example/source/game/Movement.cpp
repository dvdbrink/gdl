#include "Movement.hpp"

#include "Position.hpp"
#include "Direction.hpp"

namespace demo
{

Movement::Movement() : gdl::ces::System(Position(), Direction()) {}

void Movement::update(gdl::ces::Entity::Ptr entity, double)
{
	entity->component<Position>()->current += entity->component<Direction>()->current;
}

}
