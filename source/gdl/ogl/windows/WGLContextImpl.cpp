#include "WGLContextImpl.hpp"

#include <gdl/ogl/OpenGL.hpp>
#include <gdl/log/Emit.hpp>

#include <windows.hpp>

namespace gdl
{
namespace ogl
{

WGLContextImpl::WGLContextImpl(const gdl::sys::WindowHandle& windowHandle) :
	ContextImpl(windowHandle)
{
	deviceContext = GetDC(windowHandle);

	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int nPixelFormat = ChoosePixelFormat(deviceContext, &pfd);
	if (nPixelFormat == 0)
	{
		MessageBox(NULL, "ChoosePixelFormat Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	}

	int bResult = SetPixelFormat(deviceContext, nPixelFormat, &pfd);
	if (!bResult)
	{
		MessageBox(NULL, "SetPixelFormat Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
	}

	HGLRC tempContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, tempContext);

    if(!gl::sys::LoadFunctions() || !wgl::sys::LoadFunctions(deviceContext))
    {
        log::out<log::Fatal>() << "OpenGL context could not be created" << log::ENDL;
    }
    else
    {
    	int attributes[] =
		{
			wgl::CONTEXT_MAJOR_VERSION_ARB, 3,
			wgl::CONTEXT_MINOR_VERSION_ARB, 3,
			wgl::CONTEXT_FLAGS_ARB, wgl::CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			0
		};

    	renderContext = wgl::CreateContextAttribsARB(deviceContext, NULL, attributes);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(tempContext);
		wglMakeCurrent(deviceContext, renderContext);
    }

	std::string glVersion, glslVersion;
    glCheck(glVersion = reinterpret_cast<const char*>(gl::GetString(gl::VERSION)));
    glCheck(glslVersion = reinterpret_cast<const char*>(gl::GetString(gl::SHADING_LANGUAGE_VERSION)));
    log::out<log::Info>() << "OpenGL " << glVersion << ", GLSL " << glslVersion << log::ENDL;

    glCheck(gl::Enable(gl::DEPTH_TEST));
    glCheck(gl::DepthFunc(gl::LESS));

    glCheck(gl::Enable(gl::CULL_FACE));
    glCheck(gl::CullFace(gl::BACK));
    glCheck(gl::FrontFace(gl::CCW));
//    glCheck(gl::PolygonMode(gl::FRONT_AND_BACK, gl::LINE)); // Enable wireframe
}

WGLContextImpl::~WGLContextImpl()
{
	wglMakeCurrent(deviceContext, 0);
	wglDeleteContext(renderContext);
	ReleaseDC(windowHandle, deviceContext);
}

void WGLContextImpl::swapBuffers()
{
	::SwapBuffers(deviceContext);
}

void WGLContextImpl::setVerticalSync(bool interval)
{
	wgl::SwapIntervalEXT(interval);
}

}
}
