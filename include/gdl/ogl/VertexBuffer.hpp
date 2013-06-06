// Copyright (C) 2013 Daniel van den Brink
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#ifndef GDL_OGL_VERTEXBUFFER_HPP
#define GDL_OGL_VERTEXBUFFER_HPP

#include <gdl/ogl/Resource.hpp>
#include <gdl/ogl/OpenGL.hpp>

namespace gdl
{
namespace ogl
{

enum class BufferUsage : unsigned int
{
    Stream = gl::STREAM_DRAW,
    Static = gl::STATIC_DRAW,
    Dynamic = gl::DYNAMIC_DRAW
};

class VertexBuffer : public Resource<VertexBuffer>
{
public:
    VertexBuffer();
    VertexBuffer(const VertexBuffer&);

    VertexBuffer& operator=(const VertexBuffer&);

    void data(const void* pointer, GLsizeiptr size, BufferUsage usage);
};

}
}

#endif // GDL_OGL_VERTEXBUFFER_HPP
