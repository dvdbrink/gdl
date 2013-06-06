#ifndef GDL_GLXCONTEXTIMPL_HPP
#define GDL_GLXCONTEXTIMPL_HPP

#include <gdl/ogl/OpenGL.hpp>
#include <gdl/sys/WindowHandle.hpp>

#include "../ContextImpl.hpp"
#include "GLXExtensions.hpp"

namespace gdl
{
namespace ogl
{

class GLXContextImpl : public ContextImpl
{
public:
    GLXContextImpl(const sys::WindowHandle&);
	~GLXContextImpl();
	void swapBuffers();
	void setVerticalSync(bool);
private:
	::GLXContext context;
};

}
}

#endif // GDL_GLXCONTEXTIMPL_HPP
