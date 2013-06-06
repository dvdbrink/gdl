#include <gdl/ogl/Context.hpp>

#include <gdl/ogl/IndexBuffer.hpp>
#include <gdl/ogl/FrameBuffer.hpp>
#include <gdl/ogl/RenderBuffer.hpp>
#include <gdl/ogl/Texture.hpp>

#include "ContextImpl.hpp"

namespace gdl
{
namespace ogl
{

Context::Context(const gdl::sys::WindowHandle& windowHandle)
	: impl(ContextImpl::create(windowHandle)) {}

Context::~Context() {}

void Context::clearColor(const Color& color)
{
    glCheck(gl::ClearColor(color.r, color.g, color.b, color.a));
}

void Context::clear()
{
    glCheck(gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT | gl::STENCIL_BUFFER_BIT));
}

void Context::bind(const IndexBuffer& ib)
{
    glCheck(gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, ib.id()));
}

void Context::bind(const FrameBuffer& fb)
{
    glCheck(gl::BindFramebuffer(gl::DRAW_FRAMEBUFFER, fb.id()));
}

void Context::bind(const RenderBuffer& rb)
{
    glCheck(gl::BindRenderbuffer(gl::RENDERBUFFER, rb.id()));
}

void Context::bind(const Texture& t, const int unit)
{
    glCheck(gl::ActiveTexture(gl::TEXTURE0 + unit));
    glCheck(gl::BindTexture(gl::TEXTURE_2D, t.id()));
}

void Context::draw(const IndexBuffer&)
{
//    glCheck(gl::DrawElements());
}

void Context::update()
{
	impl->swapBuffers();
}

void Context::setVerticalSync(bool b)
{
	impl->setVerticalSync(b);
}

}
}
