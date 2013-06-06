#include <gdl/gui/TextArea.hpp>

#include <gdl/ogl/Color.hpp>

namespace gdl
{
namespace gui
{

TextArea::TextArea(sys::Window& window, const math::Vector2i& position, const Uint32 width, const Uint32 height) :
    Component(window, position, width, height),
    _rect(position, width, height, ogl::Color::Black)
{
    _rect.transparency(.7f);
}

TextArea::~TextArea()
{

}

void TextArea::render(const Viewport& viewport)
{
    if (visible())
    {
        _rect.render(viewport);
    }
}

void TextArea::absolutePositionChanged()
{
    _rect.position(absolutePosition());
}

}
}
