#ifndef GDL_OGL_RENDERBUFFER_HPP
#define GDL_OGL_RENDERBUFFER_HPP

#include <gdl/ogl/Resource.hpp>

namespace gdl
{
namespace ogl
{

class RenderBuffer : public Resource<RenderBuffer>
{
public:
    RenderBuffer();
    RenderBuffer(const RenderBuffer&);

    virtual ~RenderBuffer();

    RenderBuffer& operator=(const RenderBuffer&);
};

}
}

#endif // GDL_OGL_RENDERBUFFER_HPP
