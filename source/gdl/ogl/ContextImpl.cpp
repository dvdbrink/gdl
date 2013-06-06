#include "ContextImpl.hpp"

#include <gdl/Platform.hpp>

#if defined(GDL_PLATFORM_LINUX)
	#include "linux/GLXContextImpl.hpp"
#elif defined(GDL_PLATFORM_WINDOWS)
	#include "windows/WGLContextImpl.hpp"
#endif

namespace gdl
{
namespace ogl
{

std::unique_ptr<ContextImpl> ContextImpl::create(const sys::WindowHandle& windowHandle)
{
	#if defined(GDL_PLATFORM_LINUX)
		return std::unique_ptr<GLXContextImpl>(new GLXContextImpl(windowHandle));
	#elif defined(GDL_PLATFORM_WINDOWS)
		return std::unique_ptr<WGLContextImpl>(new WGLContextImpl(windowHandle));
	#endif
}

ContextImpl::ContextImpl(const sys::WindowHandle& windowHandle)
	: windowHandle(windowHandle) {}

ContextImpl::~ContextImpl() {}

}
}
