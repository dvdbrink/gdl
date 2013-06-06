#include <gdl/gui/Text.hpp>

#include <gdl/math/Matrix.hpp>
#include <gdl/gui/Viewport.hpp>
#include <gdl/math/Vector4.hpp>

namespace gdl
{
namespace gui
{

Text::Text(const std::string& text, const math::Vector2i& p, const ogl::Color& color) :
    _text(text),
    _color(color),
    font("resource/font/FreeSans.ttf", 20),
    vertexShader(ogl::Shader::fromFile(ogl::Shader::Vertex, "resource/shader/Font.vert")),
    fragmentShader(ogl::Shader::fromFile(ogl::Shader::Fragment, "resource/shader/Font.frag")),
    program(vertexShader, fragmentShader)
{
    position(p);
	buildGeometry();
}

Text::~Text() {}

void Text::render(const Viewport& viewport)
{
    glCheck(gl::Disable(gl::DEPTH_TEST));
    glCheck(gl::Enable(gl::BLEND));
    glCheck(gl::BlendFunc(gl::SRC_ALPHA, gl::ONE_MINUS_SRC_ALPHA));

    program.use();

	font.getTexture().bind();

    program.uniform("tex", 0);
    program.uniform("color", _color);
    program.uniform("world", transform);
    program.uniform("projection", math::ortho(viewport.x, viewport.width, viewport.height, viewport.y, 0.0f, 1.0f));

    va.draw(vb, ib, ogl::PrimitiveType::Triangles, 0, indices.size());

	font.getTexture().unbind();

    glCheck(gl::Disable(gl::BLEND));
    glCheck(gl::Enable(gl::DEPTH_TEST));
    glCheck(gl::DepthFunc(gl::LESS));
}

void Text::operator()(const std::string& text)
{
    _text = text;
    buildGeometry();
}

const std::string& Text::operator()() const
{
    return _text;
}

std::string Text::operator()()
{
    return _text;
}

const math::Vector2i& Text::position() const
{
    return _position;
}

void Text::position(const math::Vector2i& p)
{
    _position = p;
    transform = translate(transform, {static_cast<float>(_position.x), static_cast<float>(_position.y+12), 0});
}

unsigned int Text::height() const
{
    return font.getMaxHeight();
}

void Text::buildGeometry()
{
	vertices.clear();
	indices.clear();

    float x = 0;
    float y = 0;
	unsigned int i = 0;
    for (const auto character : _text)
	{
		const Glyph& glyph = font.getGlyph(character);

		float left = glyph.rect.left;
		float top = glyph.rect.top;
		float right = glyph.rect.right;
		float bottom = glyph.rect.bottom;

        float width = static_cast<float>(font.getTexture().getWidth());
        float height = static_cast<float>(font.getTexture().getHeight());
		float u1 = glyph.xOffset;
		float v1 = glyph.yOffset;
		float u2 = glyph.xOffset + glyph.rect.width / width;
        float v2 = glyph.yOffset + glyph.rect.height / height;

        math::Vector4f topLeft = {x + left , y + top, u1, v1};
        math::Vector4f topRight = {x + right, y + top, u2, v1};
        math::Vector4f bottomLeft = {x + left, y + bottom , u1, v2};
        math::Vector4f bottomRight = {x + right, y + bottom, u2, v2};

		vertices.push_back(topLeft);
		vertices.push_back(topRight);
		vertices.push_back(bottomLeft);
		vertices.push_back(bottomRight);

		indices.push_back(i + 1);
		indices.push_back(i + 0);
		indices.push_back(i + 2);
		indices.push_back(i + 1);
		indices.push_back(i + 2);
		indices.push_back(i + 3);

		x += glyph.advance.x;
		y += glyph.advance.y;

		i += 4;
	}

    vb.data(&vertices.front(), sizeof(vertices), ogl::BufferUsage::Dynamic);
    ib.data(&indices.front(), sizeof(indices), ogl::BufferUsage::Dynamic);
}

}
}
