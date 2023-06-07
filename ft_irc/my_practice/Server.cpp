#include "Server.hpp"

Server::Server(const std::string& port, const std::string& pw)
: _host("127.0.0.1"), _port(port), _pw(pw), _ipaddr("127.0.0.1")
{
	bzero(&_servaddr, sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_port = htons(std::atoi(port.c_str()));
	_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	createSocket();

	if (listen(_serv_fd, 15) < 0)
		return ;

	_kq_fd = kqueue();
	if (_kq_fd == -1)
		return ;

	EV_SET(&_evSet, _serv_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);

	int res_kevent = kevent(_kq_fd, &_evSet, 1, NULL, 0, NULL);
	if (res_kevent == -1)
		return ;
	bzero(&_evSet, sizeof(_evSet));
	
	//커맨드도 구현해서 map에 map<string, command함수> 형식으로 넣기?

}

void Server::binded()
{
	_optval = 1;
	if (setsockopt(_serv_fd, SOL_SOCKET, SO_REUSEADDR, &_optval, sizeof(int)) < 0)
		return ;
	if (bind(_serv_fd, (const struct sockaddr *)&_servaddr, sizeof(_servaddr)) < 0)
		return ;
	
	std::cout << "Success bind socket" << std::endl;	
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

void Server::serverOn()
{
	bzero(_evList, sizeof(_evList));

	struct timespec ts;
	
	ts.tv_sec = 0;
	ts.tv_nsec = 0;

	_events = kevent(_kq_fd, NULL, 0, _evList, 64, NULL);
	if (_events == -1)
		return ;

	for(int i = 0; i < _events; i++){
		client_fd = _evList[i].ident;

		if (_evList[i].flags & EV_EOF){
			// kqueue, client 삭제하기
		}else if (client_fd == _serv_fd){
			int new_client_fd;

			new_client_fd = newConnect();
			kqueue_add(new_client_fd);
		}else if (_evList[i].filter == EVFILT_READ){
			
		}
	}
}

int Server::newConnect()
{
	struct sockaddr_in clientaddr;
	socklen_t len;

	client_fd = accept(_serv_fd, (struct sockaddr *)&clientaddr, (socklen_t *)&len);
	if (client_fd == -1)
		return -1; //error

	getNameInfo((struct sockaddr*)&clientaddr);
	addClient(client_fd, clientaddr, _ipaddr);
}

void Server::getNameInfo(const sockaddr* clientaddr)
{
	char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
	if (getnameinfo(clientaddr, sizeof(struct sockaddr), hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV))
		return ;
}

void Server::addClient(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr)
{
	ClientIrc *new_client = new ClientIrc(fd_client, addrinfo_client, server_ipaddr);

	_clients.push_back(new_client);

	new_client->printClientInfo();
}

void Server::kqueueAdd(int fd)
{
	struct kevent kv;

	EV_SET(&kv, fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
	if (kevent(_kq_fd, &kv, 1, NULL, 0, NULL) == -1)
		return ;
}
