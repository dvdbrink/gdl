#include <gdl/ogl/VertexArray.hpp>

#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/ogl/IndexBuffer.hpp>

namespace gdl
{
namespace ogl
{

VertexArray::VertexArray() :
    Resource(gl::GenVertexArrays, gl::DeleteVertexArrays)
{

}

VertexArray::VertexArray(const VertexArray& copy) :
    Resource(copy)
{

}

VertexArray::~VertexArray()
{

}

VertexArray& VertexArray::operator=(const VertexArray& copy)
{
    Resource::operator=(copy);
    return *this;
}

void VertexArray::attribute(const VertexBuffer& vb, const Attribute& attribute)
{
    glCheck(gl::BindVertexArray(id()));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, vb.id()));
    glCheck(gl::VertexAttribPointer(attribute.index, attribute.size, attribute.type, gl::FALSE_, attribute.stride, attribute.offset));
    glCheck(gl::EnableVertexAttribArray(attribute.index));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, 0));
    glCheck(gl::BindVertexArray(0));
}

void VertexArray::draw(const VertexBuffer& vb, PrimitiveType mode, GLint first, GLsizei count)
{
    glCheck(gl::BindVertexArray(id()));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, vb.id()));
    glCheck(gl::DrawArrays(static_cast<GLenum>(mode), first, count));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, 0));
    glCheck(gl::BindVertexArray(0));
}

void VertexArray::draw(const VertexBuffer& vb, const IndexBuffer& ib, PrimitiveType mode, GLenum type, GLsizei count)
{
    glCheck(gl::BindVertexArray(id()));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, vb.id()));
    glCheck(gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, ib.id()));
    glCheck(gl::DrawElements(static_cast<GLenum>(mode), count, type, (const GLvoid*)0));
    glCheck(gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, 0));
    glCheck(gl::BindBuffer(gl::ARRAY_BUFFER, 0));
    glCheck(gl::BindVertexArray(0));
}

}
}
