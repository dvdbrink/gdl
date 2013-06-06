#ifndef GDL_OAL_BUFFER_HPP
#define GDL_OAL_BUFFER_HPP

#include <gdl/Types.hpp>

#include <vector>

namespace gdl
{
namespace oal
{

class File;

class Buffer
{
public:
    Buffer();
    virtual ~Buffer();

    void write(const File&);

private:
    friend class Source;
    Uint32 id;
};

}
}

#endif // GDL_OAL_BUFFER_HPP
