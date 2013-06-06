#ifndef DEMO_CONSOLE_HPP
#define DEMO_CONSOLE_HPP

#include "Renderable.hpp"

#include <gdl/Types.hpp>
#include <gdl/gui/Rectangle2D.hpp>
#include <gdl/gui/Text.hpp>
#include <gdl/sys/Keyboard.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/sys/Window.hpp>

#include <vector>
#include <memory>

namespace demo
{

class Console : public Renderable
{
public:
    Console(gdl::sys::Window&, const gdl::math::Vector2i&, const int, const int, const int, const int);
	virtual ~Console();
	void render(const gdl::math::Matrix4f&, const gdl::math::Matrix4f&);
private:
    void addLine(const std::string&);
private:
    gdl::math::Vector2i position;
	bool visible;
	bool active;
    gdl::gui::Rectangle2D rect;
    std::vector<std::shared_ptr<gdl::gui::Text>> lines;
    int heightOffset;
    const int height;
    int windowWidth;
    int windowHeight;
};

}

#endif // DEMO_CONSOLE_HPP
