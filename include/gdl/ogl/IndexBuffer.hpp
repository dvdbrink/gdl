#ifndef GDL_OGL_INDEXBUFFER_HPP
#define GDL_OGL_INDEXBUFFER_HPP

#include <gdl/ogl/Resource.hpp>
#include <gdl/ogl/OpenGL.hpp>
#include <gdl/ogl/VertexBuffer.hpp>

#include <vector>

namespace gdl
{
namespace ogl
{

class IndexBuffer :	public Resource<IndexBuffer>
{
public:
	IndexBuffer();
    IndexBuffer(const IndexBuffer&);

    IndexBuffer& operator=(const IndexBuffer&);

    void data(const void* pointer, GLsizeiptr size, BufferUsage usage);
};

}
}

#endif // GDL_OGL_INDEXBUFFER_HPP
