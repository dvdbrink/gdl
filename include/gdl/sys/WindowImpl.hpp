#ifndef GDL_SYS_WINDOWIMPL_HPP
#define GDL_SYS_WINDOWIMPL_HPP

#include <gdl/Event.hpp>
#include <gdl/sys/Keyboard.hpp>
#include <gdl/sys/Mouse.hpp>
#include <gdl/sys/WindowHandle.hpp>

#include <string>

namespace gdl
{
namespace sys
{

struct Closed {};

class WindowImpl
	: public EventBroadcaster
		<
            Closed,
			Keyboard::KeyPressed,
			Keyboard::KeyPressedRepeat,
			Keyboard::KeyReleased,
			Keyboard::TextEntered,
			Mouse::ButtonPressed,
			Mouse::ButtonReleased,
			Mouse::Motion
		>
{
public:
	static std::unique_ptr<WindowImpl> create(const std::string& title, int left, int top, unsigned int width, unsigned int height);
public:
	WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height);
	virtual ~WindowImpl();
	virtual void setTitle(const std::string&) = 0;
	virtual void setMouseVisible(bool) = 0;
	virtual void setMousePosition(int, int) = 0;
	virtual void processEvents() = 0;
	WindowHandle getHandle();
protected:
	std::string title;
	int left;
	int top;
	unsigned int width;
	unsigned int height;
	WindowHandle handle;
};

}
}

#endif // GDL_SYS_WINDOWIMPL_HPP
