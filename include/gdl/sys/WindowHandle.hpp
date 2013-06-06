#ifndef GDL_SYS_WINDOWHANDLE_HPP
#define GDL_SYS_WINDOWHANDLE_HPP

#include <gdl/Platform.hpp>
#include <gdl/ogl/OpenGL.hpp>

#if defined(GDL_PLATFORM_LINUX)
    #include <X11/Xlib.h>
#elif defined(GDL_PLATFORM_WINDOWS)
	struct HWND__;
#endif

namespace gdl
{
namespace sys
{

#if defined(GDL_PLATFORM_LINUX)
	struct _WindowHandle
	{
		unsigned long window;
		int screen;
		::Display* display;
	};
	typedef _WindowHandle WindowHandle;
#elif defined(GDL_PLATFORM_WINDOWS)
	typedef HWND__* WindowHandle;
#endif

}
}

#endif // GDL_SYS_WINDOWHANDLE_HPP
