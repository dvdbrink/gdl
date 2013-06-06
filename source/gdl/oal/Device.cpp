#include <gdl/oal/Device.hpp>

#include "OpenAL.hpp"

#include <stdexcept>

namespace gdl
{
namespace oal
{

Device::Device() :
    _device(nullptr)
{
    _device = alcOpenDevice(nullptr);
    if (!_device)
    {
        throw std::runtime_error("Unable to open audio device");
    }
}

Device::~Device()
{
    if (_device)
    {
        alcCloseDevice(_device);
    }
}

}
}


