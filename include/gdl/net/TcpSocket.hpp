#ifndef GDL_NET_TCPSOCKET_HPP
#define GDL_NET_TCPSOCKET_HPP

#include <gdl/Types.hpp>
#include <gdl/net/Socket.hpp>

#include <string>

namespace gdl
{
namespace net
{

struct Address;

class TcpSocket : public Socket
{
public:
	TcpSocket();
	TcpSocket(SocketHandle);

	virtual ~TcpSocket();

	Address getRemoteAddress() const;

	void connect(const std::string& host, const Uint32 port);
	void disconnect();
};

}
}

#endif // GDL_NET_TCPSOCKET_HPP
