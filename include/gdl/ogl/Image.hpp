#ifndef GDL_OGL_IMAGE_HPP
#define GDL_OGL_IMAGE_HPP

#include <gdl/Types.hpp>

#include <ostream>
#include <vector>

namespace gdl
{
namespace ogl
{

class Image
{
public:
	Image(const std::string&);
	virtual ~Image();
	const std::string& getName() const;
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getChannels() const;
	unsigned int getFormat() const;
	unsigned int getType() const;
	const std::vector<unsigned char> getPixels() const;
private:
	void load();
private:
	std::string name;
	unsigned int width, height, channels;
	std::vector<unsigned char> data;
};

}
}

#endif // GDL_OGL_IMAGE_HPP
