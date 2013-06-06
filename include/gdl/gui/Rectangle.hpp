#ifndef GDL_GUI_RECTANGLE_HPP
#define GDL_GUI_RECTANGLE_HPP

#include <gdl/gui/Component.hpp>
#include <gdl/gui/Rectangle2D.hpp>
#include <gdl/ogl/Color.hpp>

namespace gdl
{

namespace gui
{

struct Viewport;

class Rectangle : public Component
{
public:
    Rectangle(sys::Window&, const math::Vector2i&, const Uint32, const Uint32, const ogl::Color& = ogl::Color::White);
    virtual ~Rectangle();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    Rectangle2D _rect;
};

}
}

#endif // GDL_GUI_RECTANGLE_HPP
