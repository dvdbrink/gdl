#ifndef GDL_GUI_CONTAINER_HPP
#define GDL_GUI_CONTAINER_HPP

#include <gdl/gui/Component.hpp>

#include <vector>

namespace gdl
{
namespace gui
{

class Container : public Component
{
public:
    Container(sys::Window&, const math::Vector2i&, const Uint32, const Uint32);
    virtual ~Container();

    virtual void render(const Viewport&) override;

    template <typename C>
    void add(std::shared_ptr<C> component)
    {
        _children.push_back(component);
        component->parent(this);
    }

    template <typename C, typename... Args>
    void add(Args&&... args)
    {
        add(std::make_shared<C>(std::forward<Args>(args)...));
    }

private:
    virtual void absolutePositionChanged() override;

private:
    std::vector<std::shared_ptr<Component>> _children;
};

}
}

#endif // GDL_GUI_CONTAINER_HPP
