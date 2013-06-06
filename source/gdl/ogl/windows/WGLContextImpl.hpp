#ifndef GDL_WIN32CONTEXTIMPL_HPP
#define GDL_WIN32CONTEXTIMPL_HPP

#include <gdl/ogl/Color.hpp>
#include <gdl/sys/WindowHandle.hpp>

#include "../ContextImpl.hpp"
#include "WGLExtensions.hpp"

struct HDC__;
struct HGLRC__;

namespace gdl
{
namespace ogl
{

typedef HDC__* DeviceContext;
typedef HGLRC__* RenderContext;

class WGLContextImpl : public ContextImpl
{
public:
    WGLContextImpl(const sys::WindowHandle&);
	~WGLContextImpl();
	void swapBuffers();
    void setVerticalSync(bool);
private:
	RenderContext renderContext;
	DeviceContext deviceContext;
};

}
}

#endif // GDL_WIN32CONTEXTIMPL_HPP
