#include <gdl/ces/Entity.hpp>

namespace gdl
{
namespace ces
{

Entity::Entity(Entity::Id id) : _id(id) {}

Entity::~Entity() {}

Entity::Id Entity::id() const
{
	return _id;
}

}
}
