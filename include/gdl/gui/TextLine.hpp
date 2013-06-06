#ifndef GDL_GUI_TEXTLINE_HPP
#define GDL_GUI_TEXTLINE_HPP

#include <gdl/gui/Component.hpp>
#include <gdl/gui/Rectangle2D.hpp>
#include <gdl/gui/Text.hpp>

namespace gdl
{
namespace gui
{

class TextLine : public Component
{
public:
    TextLine(sys::Window&, const math::Vector2i&, const Uint32, const Uint32);
    virtual ~TextLine();

    void clear();
    void append(const std::string&);
    std::string text() const;
    void removeLast();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    Rectangle2D _rect;
    Text _text;
};

}
}

#endif // GDL_GUI_TEXTLINE_HPP
