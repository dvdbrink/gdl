#ifndef GDL_OAL_SOURCE_HPP
#define GDL_OAL_SOURCE_HPP

#include <gdl/Types.hpp>

namespace gdl
{
namespace oal
{

class Buffer;

class Source
{
public:
    Source();
    Source(const Buffer&);
    virtual ~Source();

    void buffer(const Buffer&);

    void play();
    void pause();
    void stop();

private:
    Uint32 id;
};

}
}

#endif // GDL_OAL_SOURCE_HPP
