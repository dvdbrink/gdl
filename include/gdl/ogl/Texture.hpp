#ifndef GDL_OGL_TEXTURE_HPP
#define GDL_OGL_TEXTURE_HPP

#include <gdl/Types.hpp>
#include <gdl/ogl/Resource.hpp>

#include <vector>

namespace gdl
{
namespace ogl
{

class Image;

enum class InternalFormat
{
    R8 = gl::R8
};

enum class Format
{
    Red = gl::RED,
    RG = gl::RG,
    RGB = gl::RGB,
    BGR = gl::BGR,
    RGBA = gl::RGBA,
    BGRA = gl::BGRA
};

enum class Type
{
    Byte = gl::BYTE,
    UnsignedByte = gl::UNSIGNED_BYTE,
    Short = gl::SHORT,
    UnsignedShort = gl::UNSIGNED_SHORT,
    Int = gl::INT,
    UnsignedInt = gl::UNSIGNED_INT,
    Float = gl::FLOAT,
    Double = gl::DOUBLE
};

enum class Wrapping
{
    ClampEdge = gl::CLAMP_TO_EDGE,
    ClampBorder = gl::CLAMP_TO_BORDER,
    Repeat = gl::REPEAT,
    MirroredRepeat = gl::MIRRORED_REPEAT
};

enum class Filter
{
    Nearest = gl::NEAREST,
    Linear = gl::LINEAR,
    NearestMipmapNearest = gl::NEAREST_MIPMAP_NEAREST,
    LinearMipmapNearest = gl::LINEAR_MIPMAP_NEAREST,
    NearestMipmapLinear = gl::NEAREST_MIPMAP_LINEAR,
    LinearMipmapLinear = gl::LINEAR_MIPMAP_LINEAR
};

class Texture : public Resource<Texture>
{
public:
    explicit Texture(const Texture&);
	Texture(InternalFormat internalFormat, unsigned int width, unsigned int height, Format format, Type type);
    explicit Texture(const Image&);
	virtual ~Texture();
    Texture& operator=(const Texture&);
	void setPixels(const unsigned char*, int xOffset, int yOffset, unsigned int width, unsigned int height);
	void setPixels(const std::vector<Uint8>& pixels, int xOffset, int yOffset, unsigned int width, unsigned int height);
	void setWrapping(Wrapping s);
	void setWrapping(Wrapping s, Wrapping t);
	void setWrapping(Wrapping s, Wrapping t, Wrapping r);
	void setFilter(Filter min, Filter mag);
	void generateMipMaps();
    void bind() const;
    void unbind() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
private:
    unsigned int width;
    unsigned int height;
};

}
}

#endif // GDL_OGL_TEXTURE_HPP
