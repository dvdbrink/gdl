#ifndef GDL_OGL_FONT_HPP
#define GDL_OGL_FONT_HPP

#include <gdl/ogl/Texture.hpp>
#include <gdl/math/Vector4.hpp>

#include <array>
#include <map>
#include <string>

namespace gdl
{
namespace gui
{

struct Rect
{
    int left = 0;
    int top = 0;
    int right = 0;
    int bottom = 0;
    int width = 0;
    int height = 0;
};

struct Advance
{
    int x = 0;
    int y = 0;
};

struct Glyph
{
    float xOffset = 0;
    float yOffset = 0;
    Rect rect;
    Advance advance;
};

class Font
{
public:
	Font(const std::string&, const unsigned int);
	virtual ~Font();
	const Glyph& getGlyph(const unsigned int character) const;
    unsigned int getMaxHeight() const;
    const ogl::Texture& getTexture();
private:
    unsigned int maxFontHeight;
	std::map<unsigned int, Glyph> glyphs;
    ogl::Texture texture;
private:
	static std::array<unsigned int, 96> charset;
};

}
}

#endif // GDL_OGL_FONT_HPP
