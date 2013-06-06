#include <gdl/gui/Font.hpp>

#include <gdl/ogl/OpenGL.hpp>
#include <gdl/log/Emit.hpp>

#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>

#include <fstream>
#include <thread>
#include <vector>
#include <sstream>

namespace gdl
{
namespace gui
{

std::array<unsigned int, 96> Font::charset = {{
	// Printable ASCII characters
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
}};

Font::Font(const std::string& fontFile, const unsigned int fontSize)
    : texture(ogl::InternalFormat::R8, 2024, 46, ogl::Format::Red, ogl::Type::UnsignedByte) // FIXME: get width and height from somewhere, width differs per platform (Linux: 2024, Windows: 2072)
{
	std::ifstream file(fontFile, std::ios::binary);
	file.seekg(0, std::ios::end);
	std::ifstream::pos_type fontDataSize = file.tellg();
	file.seekg(0, std::ios::beg);
	std::vector<char> fontData(fontDataSize);
	file.read(&fontData.front(), fontDataSize);

	stbtt_fontinfo fontInfo;
	int success = stbtt_InitFont(&fontInfo, reinterpret_cast<const unsigned char*>(&fontData.front()), 0);
	if (!success)
	{
        log::out<log::Fatal>() << "Could not init font." << log::ENDL;
	}
    float scale = stbtt_ScaleForPixelHeight(&fontInfo, static_cast<float>(fontSize));

    glCheck(gl::PixelStorei(gl::UNPACK_ALIGNMENT, 1));

	// Initialize texture
    texture.setWrapping(ogl::Wrapping::ClampEdge, ogl::Wrapping::ClampEdge);
    texture.setFilter(ogl::Filter::Linear, ogl::Filter::Linear);

	// Load glyphs
	int xOffset = 0;
	int yOffset = 0;
    int maxHeight = 0;
	for (const auto character : charset)
	{
		Glyph glyph;

		stbtt_GetCodepointHMetrics(&fontInfo, character, &glyph.advance.x, 0);
		stbtt_GetCodepointBitmapBox(&fontInfo, character, scale, scale, &glyph.rect.left, &glyph.rect.top, &glyph.rect.right, &glyph.rect.bottom);
        unsigned char* bitmap = stbtt_GetCodepointBitmap(&fontInfo, scale, scale, character, &glyph.rect.width, &glyph.rect.height, 0, 0);
        texture.setPixels(bitmap, xOffset, yOffset, glyph.rect.width, glyph.rect.height);
		stbtt_FreeBitmap(bitmap, 0);

        glyph.rect.top = glyph.rect.top;
        glyph.rect.bottom = glyph.rect.bottom;
        glyph.xOffset = xOffset / static_cast<float>(texture.getWidth());
        glyph.yOffset = yOffset / static_cast<float>(texture.getHeight());
		glyph.advance.x = static_cast<int>(glyph.advance.x * scale);

        maxHeight = std::max(maxHeight, glyph.rect.height);

		xOffset += glyph.rect.width;

		glyphs.insert(std::make_pair(character, glyph));
	}

    maxFontHeight = maxHeight;

    glCheck(gl::PixelStorei(gl::UNPACK_ALIGNMENT, 4));
}

Font::~Font() {}

const Glyph& Font::getGlyph(const unsigned int character) const
{
	return glyphs.at(character);
}

unsigned int Font::getMaxHeight() const
{
    return maxFontHeight;
}

const ogl::Texture& Font::getTexture()
{
	return texture;
}
}

}
