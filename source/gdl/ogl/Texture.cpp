#include <gdl/ogl/Texture.hpp>

#include <gdl/ogl/Image.hpp>
#include <gdl/ogl/OpenGL.hpp>

namespace gdl
{
namespace ogl
{

Texture::Texture(InternalFormat internalFormat, unsigned int width, unsigned int height, Format format, Type type) :
    Resource(gl::GenTextures, gl::DeleteTextures),
    width(width),
    height(height)
{
	bind();

    glCheck(gl::TexImage2D(gl::TEXTURE_2D, 0, static_cast<GLenum>(internalFormat), width, height, 0, static_cast<GLenum>(format), static_cast<GLenum>(type), 0));

	unbind();
}

Texture::Texture(const Image& image) :
    Resource(gl::GenTextures, gl::DeleteTextures),
    width(image.getWidth()),
    height(image.getHeight())
{
	bind();

    glCheck(gl::TexImage2D(gl::TEXTURE_2D, 0, image.getFormat(), image.getWidth(), image.getHeight(), 0, image.getFormat(), image.getType(), &image.getPixels().front()));

	unbind();
}

Texture::Texture(const Texture& copy) :
    Resource(copy)
{
    throw std::runtime_error("TODO: Texture::Texture(const Texture& copy) ");
}

Texture::~Texture()
{

}

Texture& Texture::operator=(const Texture& copy)
{
    Resource::operator=(copy);
    throw std::runtime_error("TODO: Texture& Texture::operator=(const Texture& copy)");
    return *this;
}

void Texture::setPixels(const unsigned char* ptr, int xOffset, int yOffset, unsigned int width, unsigned int height)
{
	bind();

    glCheck(gl::TexSubImage2D(gl::TEXTURE_2D, 0, xOffset, yOffset, width, height, gl::RED, gl::UNSIGNED_BYTE, ptr));

	unbind();
}

void Texture::setPixels(const std::vector<Uint8>& pixels, int xOffset, int yOffset, unsigned int width, unsigned int height)
{
	setPixels(&pixels.front(), xOffset, yOffset, width, height);
}

void Texture::setWrapping(Wrapping s)
{
	bind();

    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, static_cast<GLenum>(s)));

	unbind();
}

void Texture::setWrapping(Wrapping s, Wrapping t)
{
	bind();

    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, static_cast<GLenum>(s)));
    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, static_cast<GLenum>(t)));

	unbind();
}

void Texture::setWrapping(Wrapping s, Wrapping t, Wrapping r)
{
	bind();

    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_S, static_cast<GLenum>(s)));
    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, static_cast<GLenum>(t)));
    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_WRAP_T, static_cast<GLenum>(r)));

	unbind();
}

void Texture::setFilter(Filter min, Filter mag)
{
	bind();

    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, static_cast<GLenum>(min)));
    glCheck(gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, static_cast<GLenum>(mag)));

	unbind();
}

void Texture::generateMipMaps()
{
	bind();

    glCheck(gl::GenerateMipmap(gl::TEXTURE_2D));

	unbind();
}

void Texture::bind() const
{
    glCheck(gl::BindTexture(gl::TEXTURE_2D, id()));
}

void Texture::unbind() const
{
    glCheck(gl::BindTexture(gl::TEXTURE_2D, 0));
}

unsigned int Texture::getWidth() const
{
    return width;
}

unsigned int Texture::getHeight() const
{
    return height;
}

}
}
