#include <gdl/ogl/Program.hpp>

#include <gdl/log/Emit.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/ogl/Shader.hpp>

namespace gdl
{
namespace ogl
{

Program::Program() :
    Resource(gl::CreateProgram(), gl::DeleteProgram)
{

}

Program::Program(const Shader& vertex, const Shader& fragment) :
    Program()
{
    attach(vertex);
    attach(fragment);
    link();
}

Program::Program(const Shader& vertex, const Shader& fragment, const Shader& geometry) :
    Program()
{
    attach(vertex);
    attach(fragment);
    attach(geometry);
    link();
}

Program::Program(const Program& copy) :
    Resource(copy)
{

}

Program& Program::operator=(const Program& copy)
{
    Resource::operator=(copy);
    return *this;
}

void Program::attach(const Shader& shader)
{
    glCheck(gl::AttachShader(id(), shader.id()));
}

void Program::detach(const Shader& shader)
{
    glCheck(gl::DetachShader(id(), shader.id()));
}

void Program::link()
{
    glCheck(gl::LinkProgram(id()));
    validate();
}

void Program::use()
{
    glCheck(gl::UseProgram(id()));
}

GLint Program::attribute(const std::string& name) const
{
    auto attribute = gl::GetAttribLocation(id(), name.c_str());
    if (attribute == -1)
    {
        log::out<log::Warn>() << "Attribute " << name << " not found." << log::ENDL;
    }
    return attribute;
}

GLint Program::uniform(const std::string& name) const
{
    auto uniform = gl::GetUniformLocation(id(), name.c_str());
    if (uniform == -1)
    {
        log::out<log::Warn>() << "Uniform " << name << " not found." << log::ENDL;
    }
    return uniform;
}

void Program::uniform(const std::string& name, const math::Matrix4f& mat)
{
    glCheck(gl::UniformMatrix4fv(uniform(name), 1, false, &mat[0][0]));
}

void Program::uniform(const std::string& name, const Color& color)
{
    glCheck(gl::Uniform4f(uniform(name), color.r, color.g, color.b, color.a));
}

void Program::uniform(const std::string& name, const int i)
{
    glCheck(gl::Uniform1i(uniform(name), i));
}

void Program::uniform(const std::string& name, const float f)
{
    glCheck(gl::Uniform1f(uniform(name), f));
}

void Program::validate() const
{
    GLint linked;
    glCheck(gl::GetProgramiv(id(), gl::LINK_STATUS, &linked));
    if (!linked)
    {
        GLint infoLogLength;
        glCheck(gl::GetProgramiv(id(), gl::INFO_LOG_LENGTH, &infoLogLength));
        log::out<log::Error>() << "Program (" << id() << ") linking failed.";
        if (infoLogLength > 0)
        {
            std::string infoLog(infoLogLength, ' ');
            glCheck(gl::GetProgramInfoLog(id(), infoLogLength, &infoLogLength, &infoLog.front()));
            log::out<log::Error>() << " Reason: " << infoLog;
        }
        else
        {
            log::out<log::Error>() << log::ENDL;
        }
    }

    GLint validated;
    glCheck(gl::ValidateProgram(id()));
    glCheck(gl::GetProgramiv(id(), gl::VALIDATE_STATUS, &validated));
    if (!validated)
    {
        log::out<log::Error>() << "Error validating program " << id() << log::ENDL;
    }
}

}
}
