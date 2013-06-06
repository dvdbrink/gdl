#include <gdl/net/Socket.hpp>

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

Socket::Socket(Type type) :
	type(type)
{
	handle = socket(PF_INET, type == Type::Tcp ? SOCK_STREAM : SOCK_DGRAM, 0);

	int yes = 1;
	setsockopt(handle, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
}

Socket::Socket(Type type, SocketHandle handle) :
	handle(handle),
	type(type)
{

}

Socket::~Socket()
{
	close();
}

void Socket::close()
{
	::close(handle);
}

}
}
