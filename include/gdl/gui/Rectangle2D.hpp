#ifndef GDL_OGL_RECTANGLE2D_HPP
#define GDL_OGL_RECTANGLE2D_HPP

#include <gdl/Types.hpp>
#include <gdl/ogl/IndexBuffer.hpp>
#include <gdl/ogl/Program.hpp>
#include <gdl/ogl/Shader.hpp>
#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/ogl/VertexArray.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/math/Vector2.hpp>

#include <vector>

namespace gdl
{
namespace gui
{

struct Viewport;

class Rectangle2D
{
public:
    Rectangle2D(const math::Vector2i&, const int width, const int height, const ogl::Color& = ogl::Color::White, const float = 1.0f);
    virtual ~Rectangle2D();

    void render(const Viewport&);

    bool inRect(const math::Vector2i&) const;

    void position(const math::Vector2i&);
    const math::Vector2i& position() const;

    void color(const ogl::Color&);
    const ogl::Color& color() const;

    void transparency(float);
    const float& transparency() const;

private:
    void build();

private:
    math::Vector2i _position;
    int width;
    int height;
    ogl::Color _color;
    float _transparency;
    math::Matrix4f transform;
    ogl::Shader vs, fs;
    ogl::Program program;
    ogl::VertexBuffer vb;
    ogl::IndexBuffer ib;
    ogl::VertexArray va;
    std::vector<math::Vector3f> vertices;
    std::vector<Uint8> indices;
};

}
}

#endif // GDL_OGL_RECTANGLE2D_HPP
