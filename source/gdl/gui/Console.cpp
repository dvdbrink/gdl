#include <gdl/gui/Console.hpp>

#include <gdl/sys/Window.hpp>

namespace gdl
{
namespace gui
{

Console::Console(sys::Window& window) :
    Component(window, {0, 0}, 1400, 450),
    _line(window, {0, 400}, 1400, 50),
    _area(window, {0, 0}, 1400, 400),
    _active(false)
{
    window.connect([&](const gdl::sys::Keyboard::KeyPressed& e)
    {
        if (e.key == gdl::sys::Keyboard::Key::Enter)
        {
            _line.clear();
        }
        else if (e.key == gdl::sys::Keyboard::Key::Backspace)
        {
           _line.removeLast();
        }
    });

    window.connect([&](const gdl::sys::Keyboard::TextEntered& e)
    {
        if (visible() && _active)
        {
            _line.append(e.text);
        }
        else if (visible())
        {
            _active = true;
        }
        else
        {
            _active = false;
        }
    });
}

Console::~Console()
{

}

void Console::render(const Viewport& viewport)
{
    if (visible())
    {
        _line.render(viewport);
        _area.render(viewport);
    }
}

void Console::absolutePositionChanged()
{
    _area.position(absolutePosition());
    _line.position(absolutePosition() + gdl::math::Vector2i{0, 400});
}

}
}
