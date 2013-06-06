#include <gdl/gui/Button.hpp>

#include <gdl/sys/Window.hpp>

namespace gdl
{
namespace gui
{

Button::Button(sys::Window& window, const math::Vector2i& position, const Uint32 width, const Uint32 height, const std::string& text) :
    Rectangle(window, position, width, height, ogl::Color::Green),
    _text(text, position)
{
    window.connect([&](const sys::Mouse::ButtonPressed& e){
        if (at({e.motion.x, e.motion.y}))
        {
            signal(event::Clicked());
        }
    });
}

Button::~Button()
{

}

void Button::render(const Viewport& viewport)
{
    Rectangle::render(viewport);
    if (visible())
    {
        _text.render(viewport);
    }
}

void Button::absolutePositionChanged()
{
    Rectangle::absolutePositionChanged();
    _text.position(absolutePosition());
}

}
}
