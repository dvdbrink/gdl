#include <gdl/net/TcpServerSocket.hpp>

#include <gdl/log/Emit.hpp>

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

TcpServerSocket::TcpServerSocket(const std::string& host, const Uint32 port) :
	Socket(Type::Tcp),
	host(host),
	port(port)
{
	Uint32 status;
	struct addrinfo hints, *res, *p;
	int yes = 1;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(host.c_str(), std::to_string(port).c_str(), &hints, &res)) != 0)
	{
		std::stringstream ss;
		ss << "Error resolving address: " << gai_strerror(status);
		throw std::runtime_error(ss.str());
	}

	for (p = res; p != nullptr; p = p->ai_next)
	{
        log::out() << "ai_family:" << p->ai_family << " ai_socktype:" << p->ai_socktype << " ai_protocol:" << p->ai_protocol << log::ENDL;
		if ((handle = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
		{
            log::out<log::Info>() << "Opening socket failed" << log::ENDL;
			continue;
		}
		if (setsockopt(handle, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		{
			throw std::runtime_error("Call to setsockopt failed");
		}
		if (::bind(handle, p->ai_addr, p->ai_addrlen) == -1)
		{
			::close(handle);
            log::out<log::Info>() << "Fail to bind socket" << log::ENDL;
			continue;
		}
		break;
	}

	if (p == nullptr)
	{
		throw std::runtime_error("Failed to bind socket");
	}

	freeaddrinfo(res);
}

TcpServerSocket::~TcpServerSocket()
{

}

bool TcpServerSocket::bind()
{
//	sockaddr_in addr;
//	std::memset(addr.sin_zero, 0, sizeof(addr.sin_zero));
//	addr.sin_addr.s_addr = INADDR_ANY;
//	addr.sin_family = AF_INET;
//	addr.sin_port = port;
//
//	if (::bind(handle, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1)
//	{
//		return false;
//	}
	return true;
}

bool TcpServerSocket::listen()
{
	if (::listen(handle, 0) == -1)
	{
		return false;
	}
	return true;
}

TcpSocket TcpServerSocket::accept()
{
	struct sockaddr_storage their_addr;
	socklen_t sin_size = sizeof(their_addr);
	SocketHandle fd = ::accept(handle, (struct sockaddr *)&their_addr, &sin_size);
	return TcpSocket(fd);
}

}
}
