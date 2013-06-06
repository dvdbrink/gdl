#ifndef GDL_OGL_VERTEXARRAY_HPP
#define GDL_OGL_VERTEXARRAY_HPP

#include <gdl/ogl/Resource.hpp>
#include <gdl/ogl/PrimitiveType.hpp>

#include <vector>

namespace gdl
{
namespace ogl
{

class VertexBuffer;
class IndexBuffer;

struct Attribute
{
    GLint index;
    GLint size;
    GLenum type;
    GLsizei stride;
    const GLvoid* offset;
};

class VertexArray : public Resource<VertexArray>
{
public:
    VertexArray();
    VertexArray(const VertexArray&);

    virtual ~VertexArray();

    VertexArray& operator=(const VertexArray&);

    void attribute(const VertexBuffer&, const Attribute&);

    void draw(const VertexBuffer&, PrimitiveType, GLint, GLsizei);\
    void draw(const VertexBuffer&, const IndexBuffer&, PrimitiveType, GLenum, GLsizei);
};

}
}

#endif // GDL_OGL_VERTEXARRAY_HPP
