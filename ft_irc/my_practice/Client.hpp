#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "utility.hpp"

class Client{
protected:
	struct sockaddr_in _addrinfo;
	int _fd;
	std::string _server_ipaddr;
	std::string _host;

public:
	Client(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr);

	void getNameInfo(const sockaddr* clientaddr);
	int getFd() const;
	struct sockaddr_in getAddrInfo() const;
};

class ClientIrc: public Client{
private:
	std::string _name;
	std::string _username;
	std::string _realname;
	std::string _nickname;
	std::string _awaymessage;
	int _modes;
	bool _isconnect;
	bool _auntificated;

public:
	ClientIrc(int fd_client, sockaddr_in addrinfo_client, std::string server_ipaddr);

	void printClientInfo() const;

};

#endif
