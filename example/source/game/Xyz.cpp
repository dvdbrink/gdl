#include "Xyz.hpp"

namespace demo
{

Xyz::Xyz() :
    vs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Vertex, "resource/shader/VertexPositionColor.vert")),
    fs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Fragment, "resource/shader/VertexPositionColor.frag")),
    program(vs, fs)
{
	vertices = {
        {{ .0f,  .0f,  .0f}, gdl::ogl::Color::Red},
        {{1.0f,  .0f,  .0f}, gdl::ogl::Color::Red},
        {{ .0f,  .0f,  .0f}, gdl::ogl::Color::Green},
        {{ .0f, 1.0f,  .0f}, gdl::ogl::Color::Green},
        {{ .0f,  .0f,  .0f}, gdl::ogl::Color::Blue},
        {{ .0f,  .0f, 1.0f}, gdl::ogl::Color::Blue}
	};
    vb.data(&vertices.front(), sizeof(Vertex) * vertices.size(), gdl::ogl::BufferUsage::Static);

    va.attribute(vb, gdl::ogl::Attribute{program.attribute("position"), 3, gdl::gl::FLOAT, sizeof(Vertex), 0});
    va.attribute(vb, gdl::ogl::Attribute{program.attribute("color"), 4, gdl::gl::FLOAT, sizeof(Vertex), (const GLvoid*)12});
}

void Xyz::render(const gdl::math::Matrix4f& view, const gdl::math::Matrix4f& projection)
{
    program.use();

    program.uniform("world", transform);
    program.uniform("view", view);
    program.uniform("projection", projection);

    va.draw(vb, gdl::ogl::PrimitiveType::Lines, 0, vertices.size());
}

}
