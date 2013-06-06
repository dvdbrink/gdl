#ifndef GDL_OGL_COLOR_HPP
#define GDL_OGL_COLOR_HPP

namespace gdl
{
namespace ogl
{

class Color
{
public:
	Color(float r, float g, float b, float a);
public:
	float r, g, b, a;
public:
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
    static const Color CornflowerBlue;
};

}
}

#endif // GDL_OGL_COLOR_HPP
