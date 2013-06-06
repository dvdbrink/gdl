#ifndef GDL_CONTEXTIMPL_HPP
#define GDL_CONTEXTIMPL_HPP

#include <gdl/ogl/Color.hpp>
#include <gdl/sys/WindowHandle.hpp>

namespace gdl
{
namespace ogl
{

class ContextImpl
{
public:
    static std::unique_ptr<ContextImpl> create(const sys::WindowHandle&);
public:
    ContextImpl(const sys::WindowHandle&);
    virtual ~ContextImpl();
	virtual void swapBuffers() = 0;
	virtual void setVerticalSync(bool) = 0;
protected:
    sys::WindowHandle windowHandle;
};

}
}

#endif // GDL_CONTEXTIMPL_HPP
