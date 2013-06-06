#include <gdl/ogl/Shader.hpp>

#include <gdl/ogl/OpenGL.hpp>

#include <fstream>

namespace gdl
{
namespace ogl
{

Shader::Shader(Type type) :
    Resource(gl::CreateShader(type), gl::DeleteShader)
{

}

Shader::Shader(Type type, const std::string& code) :
    Shader(type)
{
    source(code);
    compile();
}

Shader::Shader(const Shader& copy) :
    Resource(copy)
{

}

Shader::~Shader()
{

}

Shader& Shader::operator=(const Shader& copy)
{
    Resource::operator=(copy);
    return *this;
}

void Shader::source(const std::string& code)
{
    const char* c = code.c_str();
    glCheck(gl::ShaderSource(id(), 1, &c, 0));
}

void Shader::compile()
{
    glCheck(gl::CompileShader(id()));
    validate();
}

void Shader::validate() const
{
    GLint compiled;
    glCheck(gl::GetShaderiv(id(), gl::COMPILE_STATUS, &compiled));
    if (!compiled)
    {
        log::out<log::Error>() << "Shader (" << id() << ") compilation failed.";
        GLint infoLogLength;
        glCheck(gl::GetShaderiv(id(), gl::INFO_LOG_LENGTH, &infoLogLength));
        if (infoLogLength)
        {
            std::string infoLog(infoLogLength, ' ');
            glCheck(gl::GetShaderInfoLog(id(), infoLogLength, &infoLogLength, &infoLog.front()));
            log::out<log::Error>() << " Reason: " << infoLog;
        }
        else
        {
            log::out<log::Error>() << log::ENDL;
        }
    }
}

Shader Shader::fromFile(Type type, const std::string& fileName)
{
    std::string code, line;
    std::ifstream in(fileName);
    if (in.is_open())
    {
        while (!in.eof())
        {
            std::getline(in, line);
            code.append(line);
            code.append("\n");
        }
        in.close();
    }
    return {type, code};
}

}
}
