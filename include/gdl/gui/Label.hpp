#ifndef GDL_GUI_LABEL_HPP
#define GDL_GUI_LABEL_HPP

#include <gdl/gui/Component.hpp>
#include <gdl/gui/Text.hpp>

namespace gdl
{
namespace gui
{

class Label : public Component
{
public:
    Label(sys::Window&, const math::Vector2i&, const std::string&);
    virtual ~Label();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    Text _text;
};

}
}

#endif // GDL_GUI_LABEL_HPP
