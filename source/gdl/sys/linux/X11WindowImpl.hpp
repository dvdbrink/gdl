#ifndef GDL_SYS_X11WINDOWIMPL_HPP
#define GDL_SYS_X11WINDOWIMPL_HPP

#include <gdl/sys/Keyboard.hpp>
#include <gdl/sys/Mouse.hpp>
#include <gdl/sys/WindowHandle.hpp>
#include <gdl/sys/WindowImpl.hpp>

#include <string>

namespace gdl
{
namespace sys
{

class X11WindowImpl : public WindowImpl
{
public:
	X11WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height);
	virtual ~X11WindowImpl();
	void setTitle(const std::string&);
	void setMouseVisible(bool);
	void setMousePosition(int, int);
	void processEvents();
private:
	void handleClientMessage(const ::XEvent&);
	void handleKeyPressEvent(const ::XEvent&);
	void handleKeyReleaseEvent(::XEvent&);
	void handleMouseButtonPressEvent(const ::XEvent&);
	void handleMouseButtonReleaseEvent(const ::XEvent&);
	void handleMouseMotionEvent(const ::XEvent&);
	void handleTextEvent(const ::XEvent&);
	Keyboard::Key map(const ::KeySym&);
	Mouse::Button map(const unsigned int);
	Keyboard::Key keyFromXEvent(const ::XEvent&);
	std::string stringFromXEvent(const ::XEvent&);
    int previousMouseX;
    int previousMouseY;
private:
	::Cursor hiddenCursor;
};

}
}

#endif // GDL_SYS_X11WINDOWIMPL_HPP
