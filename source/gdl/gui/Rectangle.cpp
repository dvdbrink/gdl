#include <gdl/gui/Rectangle.hpp>

namespace gdl
{
namespace gui
{

Rectangle::Rectangle(sys::Window& window, const math::Vector2i& position, const Uint32 width, const Uint32 height, const ogl::Color& color) :
    Component(window, position, width, height),
    _rect(position, width, height, color)
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::render(const Viewport& viewport)
{
    if (visible())
    {
        _rect.render(viewport);
    }
}

void Rectangle::absolutePositionChanged()
{
    _rect.position(absolutePosition());
}

}
}
