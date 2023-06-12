#pragma once

#include "utility.hpp"
#include "Client.hpp"

class Server{
private:
	std::string _host;
	std::string _port;
	std::string _pw;

	int _socket;
	struct sockaddr_in _servaddr;
	int _serv_fd;
	int _optval;
	int _listen;

	int _kq_fd;

	struct kevent _evSet;
	struct kevent _evList[64];
	int _events;
	int client_fd;

	std::string _ipaddr;
	std::vector<ClientIrc*> _clients;

public:
	Server(const std::string& host, const std::string& pw);

	void createSocket();
	void binded();

	void serverOn();

	int waitEvent();
	int newConnect();
	
	void getNameInfo(const sockaddr* clientaddr);
	void addClient(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr);
	void kqueueAdd(int fd);
};
