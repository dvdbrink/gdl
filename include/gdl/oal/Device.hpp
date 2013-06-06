#ifndef GDL_OAL_DEVICE_HPP
#define GDL_OAL_DEVICE_HPP

#include <AL/alc.h>

namespace gdl
{
namespace oal
{

class Device
{
public:
    Device();
    virtual ~Device();

private:
    friend class Context;
    ALCdevice* _device;
};

}
}

#endif // GDL_OAL_DEVICE_HPP
