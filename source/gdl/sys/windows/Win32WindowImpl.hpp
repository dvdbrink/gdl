#ifndef GDL_SYS_WIN32WINDOWIMPL_HPP
#define GDL_SYS_WIN32WINDOWIMPL_HPP

#include <gdl/Types.hpp>
#include <gdl/sys/Keyboard.hpp>
#include <gdl/sys/Mouse.hpp>
#include <gdl/sys/WindowHandle.hpp>
#include <gdl/sys/WindowImpl.hpp>

#include <windows.h>

#include <string>

namespace gdl
{
namespace sys
{

class Win32WindowImpl : public WindowImpl
{
public:
	Win32WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height);
	virtual ~Win32WindowImpl();
	void setTitle(const std::string&);
	void setMouseVisible(bool);
	void setMousePosition(int, int);
	void processEvents();
private:
	void handleCloseEvent();
    void handleInputEvent(LPARAM lParam);
	Keyboard::Key map(unsigned short);
	std::string toString(const Keyboard::Key& key);
private:
    LRESULT CALLBACK processEvent(Uint32 message, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK onEvent(WindowHandle handle, Uint32 message, WPARAM wParam, LPARAM lParam);
private:
    RAWINPUTDEVICE rid[2];
    static const std::string CLASS_NAME;
	long mousePositionX, mousePositionY;
};

}
}

#endif // GDL_SYS_WIN32WINDOWIMPL_HPP
