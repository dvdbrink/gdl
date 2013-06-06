#ifndef GDL_OGL_PROGRAM_HPP
#define GDL_OGL_PROGRAM_HPP

#include <gdl/ogl/Resource.hpp>
#include <gdl/math/Matrix.hpp>

#include <string>

namespace gdl
{
namespace ogl
{

class Color;
class Shader;

class Program : public Resource<Program>
{
public:
    Program();
    Program(const Shader&, const Shader&);
    Program(const Shader&, const Shader&, const Shader&);
    Program(const Program&);

    Program& operator=(const Program&);

    void attach(const Shader&);
    void detach(const Shader&);

    void link();
    void use();

    GLint attribute(const std::string&) const;
    GLint uniform(const std::string&) const;

    void uniform(const std::string&, const math::Matrix4f&);
    void uniform(const std::string&, const Color&);
    void uniform(const std::string&, const int);
    void uniform(const std::string&, const float);

private:
    void validate() const;
};

}
}

#endif // GDL_OGL_PROGRAM_HPP
