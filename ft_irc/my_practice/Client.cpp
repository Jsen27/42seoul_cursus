#include "Client.hpp"

Client::Client(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr)
: _fd(fd_client), _addrinfo(addrinfo_client), _server_ipaddr(server_ipaddr)
{
	getNameInfo((sockaddr*)&addrinfo_client);
}

void Client::getNameInfo(const sockaddr* clientaddr)
{
	char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
	
	if (getnameinfo(clientaddr, sizeof(struct sockaddr), hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV))
		return ;
	std::string host(hbuf);
	_host = host;
}

int Client::getFd() const
{
	return _fd;
}

struct sockaddr_in Client::getAddrInfo() const
{
	return _addrinfo;
}

ClientIrc::ClientIrc(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr)
: Client(fd_client, addrinfo_client, server_ipaddr), _name(""), _nickname(_name), _realname("None"), _isconnect(false), _auntificated(false)
{}

void ClientIrc::printClientInfo() const
{
	int port = ntohs(_addrinfo.sin_port);

	std::cout << "<-----Client Info----->" << std::endl;
	std::cout << "Server IP Adress: " << _server_ipaddr << std::endl;
	std::cout << "Port: " << port << std::endl;
	std::cout << "Name: " << _name << std::endl;
}

