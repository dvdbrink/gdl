#ifndef GDL_GUI_COMPONENT_HPP
#define GDL_GUI_COMPONENT_HPP

#include <gdl/Types.hpp>
#include <gdl/Event.hpp>
#include <gdl/math/Vector2.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/gui/Rectangle2D.hpp>
#include <gdl/log/Emit.hpp>

#include <vector>
#include <memory>

namespace gdl
{

namespace sys{class Window;}

namespace gui
{

struct Viewport;

class Component
{
public:
    Component(sys::Window&, const math::Vector2i&, const Uint32, const Uint32);
    virtual ~Component();

    void parent(Component* const);
    const Component* parent() const;

    void position(const math::Vector2i&);
    const math::Vector2i& position() const;

    void width(const Uint32&);
    const Uint32& width() const;

    void height(const Uint32&);
    const Uint32& height() const;

    void visible(const bool);
    bool visible() const;

    math::Vector2i absolutePosition() const;

    virtual void render(const Viewport&) = 0;

protected:
    bool at(const math::Vector2i&) const;

    friend class Container;
    virtual void absolutePositionChanged() = 0;

private:
    Component* _parent;
    math::Vector2i _position;
    Uint32 _width;
    Uint32 _height;
    bool _visible;
};

}
}


#endif // GDL_GUI_COMPONENT_HPP
