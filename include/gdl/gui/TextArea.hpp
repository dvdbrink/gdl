#ifndef GDL_GUI_TEXTAREA_HPP
#define GDL_GUI_TEXTAREA_HPP

#include <gdl/gui/Component.hpp>
#include <gdl/gui/Rectangle2D.hpp>

namespace gdl
{
namespace gui
{

class TextArea : public Component
{
public:
    TextArea(sys::Window&, const math::Vector2i&, const Uint32, const Uint32);
    virtual ~TextArea();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    Rectangle2D _rect;
};

}
}

#endif // GDL_GUI_TEXTAREA_HPP
