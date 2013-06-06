#include <gdl/gui/Label.hpp>

namespace gdl
{
namespace gui
{

Label::Label(sys::Window& window, const math::Vector2i& position, const std::string& text) :
    Component(window, position, 100, 20),
    _text(text, absolutePosition())
{

}

Label::~Label()
{

}

void Label::render(const Viewport &viewport)
{
    if (visible())
    {
        _text.render(viewport);
    }
}

void Label::absolutePositionChanged()
{
    _text.position(absolutePosition());
}

}
}
