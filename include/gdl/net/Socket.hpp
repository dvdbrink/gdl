#ifndef GDL_NET_SOCKET_HPP
#define GDL_NET_SOCKET_HPP

#include <gdl/Types.hpp>

namespace gdl
{
namespace net
{

using SocketHandle = Int32;

class Socket
{
public:
	enum class Type
	{
		Tcp,
		Udp
	};

public:
	Socket(Type);
	Socket(Type, SocketHandle);

	virtual ~Socket();

	void close();

protected:
	SocketHandle handle;

private:
	Type type;
};

}
}

#endif // GDL_NET_SOCKET_HPP
