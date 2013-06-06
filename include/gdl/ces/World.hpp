#ifndef GDL_CES_WORLD_HPP
#define GDL_CES_WORLD_HPP

#include <gdl/Types.hpp>
#include <gdl/ces/Entity.hpp>
#include <gdl/ces/System.hpp>

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>

namespace gdl
{
namespace ces
{

class World
{
public:
	World();
	virtual ~World();

	Entity::Ptr createEntity();

	void add(System::Ptr);

	template <typename S, typename... Args>
	void add(Args&&... args)
	{
		add(std::make_shared<S>(std::forward<Args>(args)...));
	}

	void update(double deltaTime);

private:
	Entity::Id _nextEntityId;
	std::unordered_map<Entity::Id, Entity::Ptr> _entities;
	std::vector<System::Ptr> _systems;
};

}
}

#endif // GDL_CES_WORLD_HPP
