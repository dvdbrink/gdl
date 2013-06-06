#ifndef GDL_OAL_FILE_HPP
#define GDL_OAL_FILE_HPP

#include <gdl/Types.hpp>

#include <string>
#include <vector>

namespace gdl
{
namespace oal
{

class File
{
public:
    File(const std::string &);
    virtual ~File();

    Uint32 channelCount() const;
    Uint64 sampleCount() const;
    Uint32 sampleRate() const;
    const std::vector<Int16>& samples() const;

private:
    Uint32 _channelCount;
    Uint64 _sampleCount;
    Uint32 _sampleRate;
    std::vector<Int16> _samples;
};

}
}

#endif // GDL_OAL_FILE_HPP
