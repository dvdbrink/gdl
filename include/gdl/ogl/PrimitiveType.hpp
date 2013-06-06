#ifndef GDL_OGL_PRIMITIVETYPE_HPP
#define GDL_OGL_PRIMITIVETYPE_HPP

#include <gdl/ogl/OpenGL.hpp>

namespace gdl
{
namespace ogl
{

enum class PrimitiveType : unsigned int
{
    Triangles = gl::TRIANGLES,
    TriangleStrip = gl::TRIANGLE_STRIP,
    TriangleFan = gl::TRIANGLE_FAN,
    Points = gl::POINTS,
    Lines = gl::LINES,
    LineStrip = gl::LINE_STRIP,
    LineLoop = gl::LINE_LOOP
};

}
}

#endif // GDL_OGL_PRIMITIVETYPE_HPP
