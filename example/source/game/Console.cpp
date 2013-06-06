#include "Console.hpp"

#include <gdl/ogl/Color.hpp>
#include <gdl/sys/Keyboard.hpp>
#include <gdl/gui/Viewport.hpp>
#include <gdl/log/Emit.hpp>
#include <gdl/gui/Text.hpp>

namespace demo
{

Console::Console(gdl::sys::Window& window, const gdl::math::Vector2i& position, const int width, const int height, const int windowWidth, const int windowHeight) :
    position(position),
    visible(false),
    active(false),
    rect(position, width, height),
    heightOffset(0),
    height(12),
    windowWidth(windowWidth),
    windowHeight(windowHeight)
{
    rect.transparency(.5f);
    rect.color(gdl::ogl::Color::Green);

    addLine("");

    window.connect([&](const gdl::sys::Keyboard::KeyPressed& e)
	{
        if (e.key == gdl::sys::Keyboard::Key::T)
		{
			visible = visible ? false : true;
		}
        else if (e.key == gdl::sys::Keyboard::Key::Enter)
        {
            addLine("");
        }
        else if (e.key == gdl::sys::Keyboard::Key::Backspace)
        {
            std::string str = lines.back()->operator()();
            if (str.length() > 0)
            {
                str.pop_back();
                lines.back()->operator()(str);
            }
        }
	});

    window.connect([&](const gdl::sys::Keyboard::TextEntered& e)
	{
		if (visible && active)
        {
            std::string str = lines.back()->operator()().append(e.text);
            lines.back()->operator()(str);
		}
		else if (visible)
		{
			active = true;
		}
		else
		{
			active = false;
		}
	});
}

Console::~Console() {}

void Console::render(const gdl::math::Matrix4f&, const gdl::math::Matrix4f&)
{
    if (visible)
	{
        rect.render({.0f, .0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight)});

        for (const auto text : lines)
        {
            text->render({.0f, .0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight)});
        }
	}
}

void Console::addLine(const std::string& line)
{
    auto newLine = std::make_shared<gdl::gui::Text>(line, position + gdl::math::Vector2i{0, heightOffset});
    lines.push_back(newLine);
    heightOffset += height;
}

}
