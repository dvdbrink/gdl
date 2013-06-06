#ifndef GDL_CES_SYSTEM_HPP
#define GDL_CES_SYSTEM_HPP

#include <gdl/ces/Entity.hpp>
#include <gdl/ces/Component.hpp>

#include <memory>

namespace gdl
{
namespace ces
{

class System
{
public:
	using Ptr = std::shared_ptr<System>;

public:
	System() = delete;

	template <typename... Components>
	System(const Components&... components)
	{
		createComponentMask(components...);
	}

	virtual ~System() {}

	virtual void update(Entity::Ptr, double) = 0;

	const ComponentMask& componentMask() const
	{
		return _componentMask;
	}

private:
	void createComponentMask() {}

	template <typename First, typename... Components>
	void createComponentMask(const First&, const Components&... components)
	{
		_componentMask.set(First::family());
		createComponentMask(components...);
	}

private:
	ComponentMask _componentMask;
};

}
}

#endif // GDL_CES_SYSTEM_HPP
