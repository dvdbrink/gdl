#ifndef GDL_NET_ADDRESS_HPP
#define GDL_NET_ADDRESS_HPP

#include <gdl/Types.hpp>

#include <string>

namespace gdl
{
namespace net
{

struct Address
{
	std::string ip;
	Uint32 port;
};

}
}

#endif // GDL_NET_ADDRESS_HPP
