#ifndef GDL_OGL_SHADER
#define GDL_OGL_SHADER

#include <gdl/ogl/Resource.hpp>

#include <string>

#define GLSL(x) "#version 330\n" #x

namespace gdl
{
namespace ogl
{

class Shader : public Resource<Shader>
{
public:
    enum Type
    {
        Vertex = gl::VERTEX_SHADER,
        Fragment = gl::FRAGMENT_SHADER,
        Geometry = gl::GEOMETRY_SHADER
    };

public:
    Shader(Type);
    Shader(Type, const std::string&);
    Shader(const Shader&);

    virtual ~Shader();

    Shader& operator=(const Shader&);

    void source(const std::string&);
    void compile();

private:
    void validate() const;

public:
    static Shader fromFile(Type, const std::string&);
};

}
}

#endif // GDL_OGL_SHADER
