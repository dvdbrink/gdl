#include <gdl/gui/Rectangle2D.hpp>

#include <gdl/gui/Viewport.hpp>

namespace gdl
{
namespace gui
{

Rectangle2D::Rectangle2D(const math::Vector2i& p, const int width, const int height, const ogl::Color& color, const float transparency) :
    width(width),
    height(height),
    _color(color),
    _transparency(transparency),
    vs(ogl::Shader::fromFile(ogl::Shader::Vertex, "resource/shader/Rectangle2D.vert")),
    fs(ogl::Shader::fromFile(ogl::Shader::Fragment, "resource/shader/Rectangle2D.frag")),
    program(vs, fs)
{
    position(p);
    build();
}

Rectangle2D::~Rectangle2D()
{

}

void Rectangle2D::render(const Viewport& viewport)
{
    glCheck(gl::Disable(gl::DEPTH_TEST));
    glCheck(gl::Enable(gl::BLEND));
    glCheck(gl::BlendFunc(gl::SRC_ALPHA, gl::ONE_MINUS_SRC_ALPHA));

    program.use();

    program.uniform("projection", math::ortho(viewport.x, viewport.width, viewport.height, viewport.y, .0f, 1.0f));
    program.uniform("world", transform);
    program.uniform("transparency", _transparency);
    program.uniform("color", _color);

    va.draw(vb, ib, gdl::ogl::PrimitiveType::Triangles, 0, indices.size());

    glCheck(gl::Disable(gl::BLEND));
    glCheck(gl::Enable(gl::DEPTH_TEST));
    glCheck(gl::DepthFunc(gl::LESS));
}

const math::Vector2i& Rectangle2D::position() const
{
    return _position;
}

void Rectangle2D::position(const math::Vector2i& p)
{
    _position = p;
    transform = translate(transform, {static_cast<float>(_position.x), static_cast<float>(_position.y), 0});
}

const ogl::Color& Rectangle2D::color() const
{
    return _color;
}

void Rectangle2D::color(const ogl::Color& c)
{
    _color = c;
}

const float& Rectangle2D::transparency() const
{
    return _transparency;
}

void Rectangle2D::transparency(float t)
{
    _transparency = t;
}

bool Rectangle2D::inRect(const math::Vector2i& position) const
{
    return position.x >= _position.x && position.x <= (_position.x+width) && position.y >= _position.y && position.y <=(_position.y+height);
}

void Rectangle2D::build()
{
    vertices = {
        {.0f, .0f, .0f},
        {.0f, static_cast<float>(height), .0f},
        {static_cast<float>(width), .0f, .0f},
        {static_cast<float>(width), static_cast<float>(height), .0f}
    };

    indices = {
        0, 1, 2,
        1, 3, 2
    };

    vb.data(&vertices.front(), sizeof(vertices), ogl::BufferUsage::Static);
    ib.data(&indices.front(), sizeof(indices), ogl::BufferUsage::Static);
}

}
}
