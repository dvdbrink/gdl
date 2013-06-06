#include <gdl/net/TcpSocket.hpp>

#include <gdl/net/Address.hpp>

#include <cstdio>
#include <cstring>
#include <cerrno>
#include <sstream>
#include <stdexcept>

#include <unistd.hpp>
#include <sys/types.hpp>
#include <sys/socket.hpp>
#include <netdb.hpp>
#include <arpa/inet.hpp>
#include <netinet/in.hpp>

namespace gdl
{
namespace net
{

TcpSocket::TcpSocket() : Socket(Type::Tcp)
{

}

TcpSocket::TcpSocket(SocketHandle handle) : Socket(Type::Tcp, handle)
{

}

TcpSocket::~TcpSocket()
{

}

Address TcpSocket::getRemoteAddress() const
{
	struct sockaddr_storage addr;
	socklen_t len = sizeof(addr);
	char ip[INET6_ADDRSTRLEN];
	Uint32 port;
	getpeername(handle, (struct sockaddr*)&addr, &len);

	if (addr.ss_family == AF_INET)
	{
		struct sockaddr_in *s = (struct sockaddr_in *)&addr;
		port = ntohs(s->sin_port);
		inet_ntop(AF_INET, &s->sin_addr, ip, sizeof(ip));
	}
	else
	{
		struct sockaddr_in6 *s = (struct sockaddr_in6 *)&addr;
		port = ntohs(s->sin6_port);
		inet_ntop(AF_INET6, &s->sin6_addr, ip, sizeof(ip));
	}
	return Address{ip, port};
}

void TcpSocket::connect(const std::string&, const Uint32)
{

}

void TcpSocket::disconnect()
{

}

}
}
