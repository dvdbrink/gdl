#ifndef GDL_CES_ENTITY_HPP
#define GDL_CES_ENTITY_HPP

#include <gdl/Types.hpp>
#include <gdl/ces/Component.hpp>

#include <unordered_map>
#include <memory>
#include <stdexcept>

namespace gdl
{
namespace ces
{

using ComponentMap = std::unordered_map<BaseComponent::Family, std::shared_ptr<BaseComponent>>;

class Entity
{
public:
	using Id = Uint64;
	using Ptr = std::shared_ptr<Entity>;

public:
	virtual ~Entity();

	Id id() const;

	template <typename C>
	void add(std::shared_ptr<C> component)
	{
		_components.insert(std::make_pair(C::family(), component));
		_componentMask.set(C::family());
	}

	template <typename C, typename... Args>
	void add(Args&&... args)
	{
		add(std::make_shared<C>(std::forward<Args>(args)...));
	}

	template <typename C>
	std::shared_ptr<C> component()
	{
		if (!_componentMask.test(C::family()))
		{
			throw std::runtime_error("No such component");
		}
		auto base = _components.at(C::family());
		return std::static_pointer_cast<C>(base);
	}

	const ComponentMask& componentMask() const
	{
		return _componentMask;
	}

private:
	friend class World;
	Entity(Id id);

	Id _id;
	ComponentMap _components;
	ComponentMask _componentMask;
};

}
}

#endif // GDL_CES_ENTITY_HPP
