#ifndef GDL_GUI_CONSOLE_HPP
#define GDL_GUI_CONSOLE_HPP

#include <gdl/gui/Component.hpp>
#include <gdl/gui/TextLine.hpp>
#include <gdl/gui/TextArea.hpp>

namespace gdl
{
namespace gui
{

class Console : public Component
{
public:
    Console(sys::Window&);
    virtual ~Console();

    virtual void render(const Viewport&) override;

protected:
    virtual void absolutePositionChanged() override;

private:
    TextLine _line;
    TextArea _area;
    bool _active;
};

}
}

#endif // GDL_GUI_CONSOLE_HPP
