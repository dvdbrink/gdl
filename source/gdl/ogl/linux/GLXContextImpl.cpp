#include "GLXContextImpl.hpp"

#include <gdl/log/Emit.hpp>

#include <string>

namespace gdl
{
namespace ogl
{

GLXContextImpl::GLXContextImpl(const gdl::sys::WindowHandle& windowHandle) :
	ContextImpl(windowHandle)
{
	::XWindowAttributes windowAttributes;
	::XGetWindowAttributes(windowHandle.display, windowHandle.window, &windowAttributes);

	::XVisualInfo visualInfo;
	visualInfo.depth = windowAttributes.depth;
	visualInfo.visualid = ::XVisualIDFromVisual(windowAttributes.visual);
	visualInfo.screen = windowHandle.screen;

	int nbVisuals = 0;
	::XVisualInfo* visuals = ::XGetVisualInfo(windowHandle.display, VisualDepthMask | VisualIDMask | VisualScreenMask, &visualInfo, &nbVisuals);

	::GLXContext tempContext = glXCreateContext(windowHandle.display, visuals, NULL, gl::FALSE_);
	glXMakeCurrent(windowHandle.display, windowHandle.window, tempContext);
	glXDestroyContext(windowHandle.display, tempContext);

    int nbConfigs = 0;
    ::GLXFBConfig* configs = ::glXChooseFBConfig(windowHandle.display, windowHandle.screen, NULL, &nbConfigs);

    if(!gl::sys::LoadFunctions() || !glX::sys::LoadFunctions(windowHandle.display, windowHandle.screen))
    {
        log::out<log::Fatal>() << "OpenGL context could not be created" << log::ENDL;
    }
    else
    {
    	int contextAttributes[] =
		{
			glX::CONTEXT_MAJOR_VERSION_ARB, 3,
			glX::CONTEXT_MINOR_VERSION_ARB, 3,
			glX::CONTEXT_FLAGS_ARB, glX::CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};
		context = glX::CreateContextAttribsARB(windowHandle.display, configs[0], NULL, gl::TRUE_, contextAttributes);
		::glXMakeCurrent(windowHandle.display, windowHandle.window, context);

		::Colormap colorMap = ::XCreateColormap(windowHandle.display, RootWindow(windowHandle.display, windowHandle.screen), visuals[0].visual, AllocNone);
		::XSetWindowColormap(windowHandle.display, windowHandle.window, colorMap);
		::XFree(visuals);

	    std::string glVersion, glslVersion;
        glCheck(glVersion = reinterpret_cast<const char*>(gl::GetString(gl::VERSION)));
        glCheck(glslVersion = reinterpret_cast<const char*>(gl::GetString(gl::SHADING_LANGUAGE_VERSION)));
        log::out<log::Info>() << "OpenGL " << glVersion << ", GLSL " << glslVersion << log::ENDL;

        glCheck(gl::Enable(gl::DEPTH_TEST));
        glCheck(gl::DepthFunc(gl::LESS));

        glCheck(gl::Enable(gl::CULL_FACE));
        glCheck(gl::CullFace(gl::BACK));
        glCheck(gl::FrontFace(gl::CCW));
		// glCheck(gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE)); // Enable wireframe
	}
}

GLXContextImpl::~GLXContextImpl()
{
	::glXMakeCurrent(windowHandle.display, 0, 0);
	::glXDestroyContext(windowHandle.display, context);
}

void GLXContextImpl::swapBuffers()
{
	::glXSwapBuffers(windowHandle.display, windowHandle.window);
}

void GLXContextImpl::setVerticalSync(bool interval)
{
	glX::SwapIntervalEXT(windowHandle.display, windowHandle.window, interval);
}

}
}
