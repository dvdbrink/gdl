#include <gdl/oal/File.hpp>

#include <gdl/log/Emit.hpp>

#include <stb_vorbis.c>

#include <stdexcept>

namespace gdl
{
namespace oal
{

File::File(const std::string& fileName) :
    _channelCount(0),
    _sampleCount(0),
    _sampleRate(0)
{
    stb_vorbis* file = stb_vorbis_open_filename(const_cast<char*>(fileName.c_str()), 0, 0);
    if (file)
    {
        stb_vorbis_info info = stb_vorbis_get_info(file);
        _channelCount = info.channels;
        _sampleRate   = info.sample_rate;

        int samples = stb_vorbis_stream_length_in_samples(file) * _channelCount;
        _sampleCount  = samples;
        _samples.resize(samples);

        stb_vorbis_get_samples_short_interleaved(file, _channelCount, &_samples.front(), samples);

        stb_vorbis_close(file);
    }
    else
    {
        throw std::runtime_error("Unable to open audio file");
    }
}

File::~File()
{

}

Uint32 File::channelCount() const
{
    return _channelCount;
}

Uint64 File::sampleCount() const
{
    return _sampleCount;
}

Uint32 File::sampleRate() const
{
    return _sampleRate;
}

const std::vector<Int16> &File::samples() const
{
    return _samples;
}

}
}
