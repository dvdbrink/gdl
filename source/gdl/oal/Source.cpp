#include <gdl/oal/Source.hpp>

#include <gdl/oal/Buffer.hpp>

#include "OpenAL.hpp"

namespace gdl
{
namespace oal
{

Source::Source() :
    id(0)
{
    alCheck(alGenSources(1, &id));
}

Source::Source(const Buffer& buf) :
    Source()
{
    buffer(buf);
}

Source::~Source()
{
    stop();
    if (id)
    {
        alCheck(alDeleteSources(1, &id));
    }
}

void Source::buffer(const Buffer& buffer)
{
    alCheck(alSourcei(id, AL_BUFFER, buffer.id));
}

void Source::play()
{
    alCheck(alSourcePlay(id));
}

void Source::pause()
{
    alCheck(alSourcePause(id));
}

void Source::stop()
{
    alCheck(alSourceStop(id));
}

}
}


