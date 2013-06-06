#ifndef GDL_OGL_TEXT_HPP
#define GDL_OGL_TEXT_HPP

#include <gdl/gui/Font.hpp>
#include <gdl/ogl/IndexBuffer.hpp>
#include <gdl/ogl/Program.hpp>
#include <gdl/ogl/Shader.hpp>
#include <gdl/ogl/VertexArray.hpp>
#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/math/Vector2.hpp>

#include <string>

namespace gdl
{
namespace gui
{

struct Viewport;

class Text
{
public:
    Text(const std::string&, const math::Vector2i&, const ogl::Color& = ogl::Color::Red);
	~Text();
    void render(const Viewport&);

    void operator()(const std::string&);
    const std::string& operator()() const;
    std::string operator()();

    void position(const math::Vector2i&);
    const math::Vector2i& position() const;

    unsigned int height() const;

private:
    std::string _text;
    ogl::Color _color;
    math::Vector2i _position;
	Font font;
    ogl::Shader vertexShader, fragmentShader;
ogl::Program program;
    ogl::VertexArray va;
    ogl::VertexBuffer vb;
    ogl::IndexBuffer ib;
    math::Matrix4f transform;
    std::vector<math::Vector4f> vertices;
    std::vector<Uint32> indices;

private:
	void buildGeometry();
};

}
}

#endif // GDL_OGL_TEXT_HPP
