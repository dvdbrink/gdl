#include <gdl/gui/Container.hpp>

#include <gdl/gui/Viewport.hpp>

namespace gdl
{
namespace gui
{

Container::Container(sys::Window& window, const math::Vector2i& position, const Uint32 width, const Uint32 height) :
    Component(window, position, width, height)
{

}

Container::~Container()
{

}

void Container::render(const Viewport& viewport)
{
    if (visible())
    {
        for (const auto& child : _children)
        {
            child->render(viewport);
        }
    }
}

void Container::absolutePositionChanged()
{
    for (const auto& child : _children)
    {
        child->absolutePositionChanged();
    }
}

}
}
