#include <gdl/ogl/FrameBuffer.hpp>

namespace gdl
{
namespace ogl
{

FrameBuffer::FrameBuffer() :
    Resource(gl::GenFramebuffers, gl::DeleteFramebuffers)
{

}

FrameBuffer::FrameBuffer(const FrameBuffer& copy) :
    Resource(copy)
{

}

FrameBuffer::~FrameBuffer()
{

}

FrameBuffer& FrameBuffer::operator=(const FrameBuffer& copy)
{
    Resource::operator=(copy);
    return *this;
}

void FrameBuffer::bind()
{
    glCheck(gl::BindFramebuffer(gl::FRAMEBUFFER, id()));
}

void FrameBuffer::unbind()
{
    glCheck(gl::BindFramebuffer(gl::FRAMEBUFFER, 0));
}

}
}
