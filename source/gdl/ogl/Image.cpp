#include <gdl/ogl/Image.hpp>

#include <gdl/ogl/OpenGL.hpp>
#include <gdl/log/Emit.hpp>

#include <stb_image.h>

namespace gdl
{
namespace ogl
{

Image::Image(const std::string& image)
	: name(image), width(0), height(0), channels(4)
{
	load();
}

Image::~Image() {}

const std::string& Image::getName() const
{
	return name;
}

unsigned int Image::getWidth() const
{
	return width;
}

unsigned int Image::getHeight() const
{
	return height;
}

unsigned int Image::getChannels() const
{
	return channels;
}

unsigned int Image::getFormat() const
{
    return gl::RGBA;
}

unsigned int Image::getType() const
{
    return gl::UNSIGNED_BYTE;
}

const std::vector<unsigned char> Image::getPixels() const
{
	return data;
}

void Image::load()
{
	int x, y, n;
	unsigned char* pointer = stbi_load(name.c_str(), &x, &y, &n, static_cast<int>(channels));

	if (pointer && x && y)
	{
		width = static_cast<unsigned int>(x);
		height = static_cast<unsigned int>(y);

		data.assign(pointer, pointer + (width * height * channels));

		stbi_image_free(pointer);
	}
	else
	{
        log::out<log::Error>() << "Failed to load image " << name << ". Reason: " << stbi_failure_reason() << log::ENDL;
	}
}

}
}
