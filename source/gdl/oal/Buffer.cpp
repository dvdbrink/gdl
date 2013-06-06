#include <gdl/oal/Buffer.hpp>

#include <gdl/oal/File.hpp>

#include "OpenAL.hpp"

namespace gdl
{
namespace oal
{

Buffer::Buffer() :
    id(0)
{
    alCheck(alGenBuffers(1, &id));
}

Buffer::~Buffer()
{
    if (id)
    {
        alCheck(alDeleteBuffers(1, &id));
    }
}

void Buffer::write(const File& file)
{
    alCheck(alBufferData(id, AL_FORMAT_STEREO16, &file.samples().front(), file.samples().size() * sizeof(Int16), file.sampleRate()));
}

}
}
