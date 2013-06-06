#ifndef GDL_OAL_CONTEXT_HPP
#define GDL_OAL_CONTEXT_HPP

#include <AL/alc.h>

namespace gdl
{
namespace oal
{

class Device;

class Context
{
public:
    Context(const Device&);
    virtual ~Context();

private:
    ALCcontext* _context;
};

}
}

#endif // GDL_OAL_CONTEXT_HPP
