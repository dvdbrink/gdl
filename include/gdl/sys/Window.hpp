#ifndef GDL_SYS_WINDOW_HPP
#define GDL_SYS_WINDOW_HPP

#include <gdl/Event.hpp>
#include <gdl/sys/Keyboard.hpp>
#include <gdl/sys/Mouse.hpp>
#include <gdl/sys/WindowHandle.hpp>
#include <gdl/sys/WindowImpl.hpp>

#include <string>
#include <memory>

namespace gdl
{
namespace sys
{

class Window
{
public:
	Window(const std::string& title, int left, int top, unsigned int width, unsigned int height)
        : impl(WindowImpl::create(title, left, top, width, height)) {}

	virtual ~Window() {}

	template <typename Connection>
	void connect(Connection&& connection)
	{
		impl->connect(std::move(connection));
	}

	void processEvents()
	{
		impl->processEvents();
	}

	void setTitle(const std::string& title)
	{
		impl->setTitle(title);
	}

	void setMouseVisible(bool visible)
	{
		impl->setMouseVisible(visible);
	}

	void setMousePosition(int left, int top)
	{
		impl->setMousePosition(left, top);
	}

    WindowHandle handle()
	{
		return impl->getHandle();
	}
private:
	std::unique_ptr<WindowImpl> impl;
};

}
}

#endif // GDL_SYS_WINDOW_HPP
