#include "Crosshair.hpp"

namespace demo
{

Crosshair::Crosshair() :
    vs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Vertex, "resource/shader/Overlay.vert")),
    fs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Fragment, "resource/shader/Overlay.frag")),
    program(vs, fs)
{
	vertices = {
        {-.02f,  .0f, .0f},
        { .02f,  .0f, .0f},
        { .0f, -.02f, .0f},
        { .0f,  .02f, .0f}
	};
    vb.data(&vertices.front(), sizeof(gdl::math::Vector3f) * vertices.size(), gdl::ogl::BufferUsage::Static);

    va.attribute(vb, {program.attribute("position"), 3, gdl::gl::FLOAT, sizeof(gdl::math::Vector3f), 0});
}

void Crosshair::render(const gdl::math::Matrix4f&, const gdl::math::Matrix4f&)
{
    program.use();
    program.uniform("world", transform);

    va.draw(vb, gdl::ogl::PrimitiveType::Lines, 0, vertices.size());
}

}
