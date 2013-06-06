#include <gdl/gui/Component.hpp>

#include <gdl/gui/Viewport.hpp>
#include <gdl/sys/Window.hpp>

namespace gdl
{
namespace gui
{

Component::Component(sys::Window&, const math::Vector2i& position, const Uint32 width, const Uint32 height) :
    _parent(nullptr),
    _position(position),
    _width(width),
    _height(height),
    _visible(true)
{

}

Component::~Component()
{

}

void Component::parent(Component* const parent)
{
    _parent = parent;
    absolutePositionChanged();
}

const Component* Component::parent() const
{
    return _parent;
}

void Component::position(const math::Vector2i& position)
{
    _position = position;
    absolutePositionChanged();
}

const math::Vector2i& Component::position() const
{
    return _position;
}

void Component::width(const Uint32& width)
{
    _width = width;
}

const Uint32& Component::width() const
{
    return _width;
}

void Component::height(const Uint32& height)
{
    _height = height;
}

const Uint32& Component::height() const
{
    return _height;
}

void Component::visible(const bool visible)
{
    _visible = visible;
}

bool Component::visible() const
{
    return _visible;
}

math::Vector2i Component::absolutePosition() const
{
    if (_parent)
    {
        return {_parent->position().x + _position.x, _parent->position().y + _position.y};
    }
    return {_position.x, _position.y};
}

bool Component::at(const math::Vector2i& point) const
{
    auto position = absolutePosition();
    return point.x >= position.x && point.x <= (position.x + static_cast<Int32>(_width)) && point.y >= position.y && point.y <= (position.y + static_cast<Int32>(_height));
}

}
}
