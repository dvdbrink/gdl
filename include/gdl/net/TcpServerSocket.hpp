#ifndef GDL_NET_TCPSERVERSOCKET_HPP
#define GDL_NET_TCPSERVERSOCKET_HPP

#include <gdl/net/Socket.hpp>
#include <gdl/net/TcpSocket.hpp>

#include <string>

namespace gdl
{
namespace net
{

class TcpServerSocket : public Socket
{
public:
	TcpServerSocket(const std::string& host, const Uint32 port);
	virtual ~TcpServerSocket();

	bool bind();
	bool listen();
	TcpSocket accept();

private:
	std::string host;
	Uint32 port;
};

}
}

#endif // GDL_NET_TCPSERVERSOCKET_HPP
