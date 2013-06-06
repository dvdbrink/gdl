#include <gdl/ces/World.hpp>

namespace gdl
{
namespace ces
{

World::World() : _nextEntityId(0) {}

World::~World() {}

Entity::Ptr World::createEntity()
{
	Entity::Id id = _nextEntityId++;
	auto entity = Entity::Ptr(new Entity(id));
	_entities.insert(std::make_pair(id, entity));
	return entity;
}

void World::add(System::Ptr system)
{
	_systems.push_back(system);
}

void World::update(double deltaTime)
{
	for (auto entity : _entities)
	{
		for (auto system : _systems)
		{
			if ((entity.second->componentMask() & system->componentMask()) == system->componentMask())
			{
				system->update(entity.second, deltaTime);
			}
		}
	}
}

}
}
