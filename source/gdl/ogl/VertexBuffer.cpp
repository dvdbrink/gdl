#include <gdl/ogl/VertexBuffer.hpp>

namespace gdl
{
namespace ogl
{

VertexBuffer::VertexBuffer() :
    Resource(gl::GenBuffers, gl::DeleteBuffers)
{

}

VertexBuffer::VertexBuffer(const VertexBuffer& copy) :
    Resource(copy)
{

}

VertexBuffer& VertexBuffer::operator=(const VertexBuffer& copy)
{
    Resource::operator=(copy);
    return *this;
}

void VertexBuffer::data(const void* pointer, GLsizeiptr size, BufferUsage usage)
{
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, id()));
    glCheck(gl::BufferData(gl::ARRAY_BUFFER, size, pointer, static_cast<GLenum>(usage)));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, 0));
}

}
}
