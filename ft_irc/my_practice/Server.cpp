#include "Server.hpp"

Server::Server(const std::string& port, const std::string& pw)
: _host("127.0.0.1"), _port(port), _pw(pw)
{
	bzero(&_servaddr, sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_port = htons(std::atoi(port.c_str()));
	_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	createSocket();

	_optval = 1;
	if (setsockopt(_serv_fd, SOL_SOCKET, SO_REUSEADDR, &_optval, sizeof(int)) < 0)
		return ;
	if (bind(_serv_fd, (const struct sockaddr *)&_servaddr, sizeof(_servaddr)) < 0)
		return ;
	
	std::cout << "Success bind socket" << std::endl;

	if (listen(_serv_fd, 15) < 0)
		return ;

	int res_kevent;

	_kq_fd = kqueue();
	if (_kq_fd == -1)
		return ;

}


void Server::createSocket()
{
	// 2 = TCP , 1 = stream socket
	_serv_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	if (_serv_fd < 0)
		return ; //error
	
	std::cout << "Socket fd(" << _serv_fd << ") successfully created" << std::endl;
	fcntl(_serv_fd, F_SETFL, O_NONBLOCK);
}
