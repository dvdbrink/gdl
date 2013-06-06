#include <gdl/ogl/IndexBuffer.hpp>

#include <stdexcept>

namespace gdl
{
namespace ogl
{

IndexBuffer::IndexBuffer() :
    Resource(gl::GenBuffers, gl::DeleteBuffers)
{

}

IndexBuffer::IndexBuffer(const IndexBuffer& copy) :
    Resource(copy)
{

}

IndexBuffer& IndexBuffer::operator=(const IndexBuffer& copy)
{
    Resource::operator=(copy);
    return *this;
}

void IndexBuffer::data(const void* pointer, GLsizeiptr size, BufferUsage usage)
{
    glCheck(gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, id()));
    glCheck(gl::BufferData(gl::ELEMENT_ARRAY_BUFFER, size, pointer, static_cast<GLenum>(usage)));
    glCheck(gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, 0));
}

}
}
