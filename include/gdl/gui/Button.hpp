#ifndef GDL_GUI_BUTTON_HPP
#define GDL_GUI_BUTTON_HPP

#include <gdl/gui/Rectangle.hpp>
#include <gdl/gui/Text.hpp>

#include <string>

namespace gdl
{
namespace gui
{
namespace event
{
struct Clicked {};
}

class Button :
    public Rectangle,
    public EventBroadcaster<event::Clicked>
{
public:
    Button(sys::Window&, const math::Vector2i&, const Uint32, const Uint32, const std::string&);
    virtual ~Button();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    Text _text;
};

}
}

#endif // GDL_GUI_BUTTON_HPP
