#ifndef GDL_OGL_OPENAL_HPP
#define GDL_OGL_OPENAL_HPP

#define alCheck(call) ((call), gdl::oal::alError(__FILE__, __LINE__))

#include <gdl/log/Emit.hpp>

#include <AL/al.h>
#include <AL/alc.h>

#include <string>

namespace gdl
{
namespace oal
{

class OpenAL
{
public:
    static log::ForegroundColor foregroundColor()
    {
        return log::ForegroundColor::RED;
    }
    static log::BackgroundColor backgroundColor()
    {
        return log::BackgroundColor::DEFAULT;
    }
    static log::Level level()
    {
        return log::Level::ERROR;
    }
    static const std::string description()
    {
        return "[OPENAL] ";
    }
};

inline void alError(const std::string& file, unsigned int line)
{
    ALenum errorCode(alGetError());

    if (errorCode != AL_NO_ERROR)
    {
        std::string error;

        switch (errorCode)
        {
            case AL_INVALID_NAME: 		error = "AL_INVALID_NAME"; 		break;
            case AL_INVALID_ENUM:       error = "AL_INVALID_ENUM";      break;
            case AL_INVALID_VALUE:      error = "AL_INVALID_VALUE";     break;
            case AL_INVALID_OPERATION: 	error = "AL_INVALID_OPERATION"; break;
            case AL_OUT_OF_MEMORY:      error = "AL_OUT_OF_MEMORY"; 	break;
            default: error = "Unknown error";
        }

        log::out<OpenAL>() << "(" << file << ", " << line << ") " << error << log::ENDL;
    }
}

}
}

#endif // GDL_OGL_OPENAL_HPP
