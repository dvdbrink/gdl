#include <gdl/ogl/RenderBuffer.hpp>

namespace gdl
{
namespace ogl
{

RenderBuffer::RenderBuffer() :
    Resource(gl::GenRenderbuffers, gl::DeleteRenderbuffers)
{

}

RenderBuffer::RenderBuffer(const RenderBuffer& copy) :
    Resource(copy)
{

}

RenderBuffer::~RenderBuffer()
{

}

RenderBuffer& RenderBuffer::operator=(const RenderBuffer& copy)
{
    Resource::operator=(copy);
    return *this;
}

}
}
