#include <gdl/sys/WindowImpl.hpp>

#include <gdl/Platform.hpp>

#if defined(GDL_PLATFORM_LINUX)
    #include "linux/X11WindowImpl.hpp"
#elif defined(GDL_PLATFORM_WINDOWS)
    #include "windows/Win32WindowImpl.hpp"
#endif

namespace gdl
{
namespace sys
{

std::unique_ptr<WindowImpl> WindowImpl::create(const std::string& title, int left, int top, unsigned int width, unsigned int height)
{
	#if defined(GDL_PLATFORM_LINUX)
		return std::unique_ptr<X11WindowImpl>(new X11WindowImpl(title, left, top, width, height));
	#elif defined(GDL_PLATFORM_WINDOWS)
		return std::unique_ptr<Win32WindowImpl>(new Win32WindowImpl(title, left, top, width, height));
	#endif
}

WindowImpl::WindowImpl(const std::string& title, int left, int top, unsigned int width, unsigned int height)
	: title(title), left(left), top(top), width(width), height(height) {}

WindowImpl::~WindowImpl() {}

WindowHandle WindowImpl::getHandle()
{
	return handle;
}

}
}
