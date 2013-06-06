#ifndef GDL_OGL_FRAMEBUFFER_HPP
#define GDL_OGL_FRAMEBUFFER_HPP

#include <gdl/ogl/Resource.hpp>

namespace gdl
{
namespace ogl
{

class FrameBuffer : public Resource<FrameBuffer>
{
public:
    FrameBuffer();
    FrameBuffer(const FrameBuffer&);

    virtual ~FrameBuffer();

    FrameBuffer& operator=(const FrameBuffer&);

    void bind();
    void unbind();
};

}
}

#endif // GDL_OGL_FRAMEBUFFER_HPP
