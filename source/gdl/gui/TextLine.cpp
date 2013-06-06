#include <gdl/gui/TextLine.hpp>

#include <sstream>

namespace gdl
{
namespace gui
{

TextLine::TextLine(sys::Window& window, const math::Vector2i& position, const Uint32 width, const Uint32 height) :
    Component(window, position, width, height),
    _rect(position, width, height, ogl::Color::Black),
    _text("...", position, ogl::Color::White)
{
    _rect.transparency(.7f);
    auto avg = (height - _text.height()) / 2;
    _text.position(_text.position() + gdl::math::Vector2i{static_cast<int>(avg), static_cast<int>(avg)});
}

TextLine::~TextLine()
{

}

void TextLine::clear()
{
    _text("");
}

void TextLine::append(const std::string& str)
{
    std::stringstream iss;
    iss << _text() << str;
    _text(iss.str());
}

std::string TextLine::text() const
{
    return _text();
}

void TextLine::removeLast()
{
    auto str = _text();
    if (str.length() > 0)
    {
        str.pop_back();
    }
    _text(str);
}

void TextLine::render(const Viewport& viewport)
{
    if (visible())
    {
        _rect.render(viewport);
        _text.render(viewport);
    }
}

void TextLine::absolutePositionChanged()
{

}

}
}

