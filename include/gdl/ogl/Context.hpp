#ifndef GDL_OGL_CONTEXT_HPP
#define GDL_OGL_CONTEXT_HPP

#include <gdl/ogl/Color.hpp>
#include <gdl/sys/WindowHandle.hpp>

#include <memory>

namespace gdl
{
namespace ogl
{

class IndexBuffer;
class FrameBuffer;
class RenderBuffer;
class Texture;

class ContextImpl;

class Context
{
public:
    Context(const gdl::sys::WindowHandle&);
	~Context();

    void clearColor(const Color&);
    void clear();

    void bind(const IndexBuffer&);
    void bind(const FrameBuffer&);
    void bind(const RenderBuffer&);
    void bind(const Texture&, const int = 0);

    void draw(const IndexBuffer&);

    void update();
	void setVerticalSync(bool);

private:
	std::unique_ptr<ContextImpl> impl;
};

}
}

#endif // GDL_OGL_CONTEXT_HPP
