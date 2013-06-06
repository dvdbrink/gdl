#ifndef GDL_OGL_OPENGL_HPP
#define GDL_OGL_OPENGL_HPP

#include <gdl/log/Emit.hpp>

#include "Extensions.hpp"

#include <string>

#define glCheck(call) ((call), gdl::ogl::glError(__FILE__, __LINE__))

namespace gdl
{
namespace ogl
{

class OpenGL
{
public:
	static log::ForegroundColor foregroundColor()
	{
		return log::ForegroundColor::BLUE;
	}
	static log::BackgroundColor backgroundColor()
	{
		return log::BackgroundColor::DEFAULT;
	}
	static log::Level level()
	{
		return log::Level::FATAL;
	}
	static const std::string description()
	{
		return "[OPENGL] ";
	}
};

inline void glError(const std::string& file, unsigned int line)
{
    GLenum errorCode(gl::GetError());

    if (errorCode != gl::NO_ERROR_)
	{
		std::string error;

		switch (errorCode)
		{
            case gl::INVALID_ENUM: 		error = "GL_INVALID_ENUM"; 		break;
            case gl::INVALID_VALUE: 	error = "GL_INVALID_VALUE"; 	break;
            case gl::INVALID_OPERATION: error = "GL_INVALID_OPERATION"; break;
            case gl::OUT_OF_MEMORY: 	error = "GL_OUT_OF_MEMORY"; 	break;
            case gl::TABLE_TOO_LARGE: 	error = "GL_TABLE_TOO_LARGE"; 	break;
			default: error = "Unknown error";
		}

        log::out<OpenGL>() << "(" << file << ", " << line << ") " << error << log::ENDL;
	}
}

}
}

#endif // GDL_OGL_OPENGL_HPP
