#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sstream>

#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h>	/* inet_addr inet_htop */
#include <sys/socket.h>	/* socket */
#include <sys/event.h> /* kqueue */
#include <netdb.h>		/* getnameinfo */
#include <errno.h>		/* errno */
#include <fcntl.h>		/* open */
#include <unistd.h>		/* write */
#include <fcntl.h>		/* fcntl */

#include <iomanip>
#include <fstream>
#include <iostream>		/* std cout */
#include <ctime>		/* time */
#include <map>			/* map */
#include <vector>		/* vector */
#include <set>			/* set	*/

#include <strings.h>	/* bzero */
#include <string.h>		/* strerror */

#define	BUFFER_SIZE_SEND	1024		//Send
#define RECV_BUFFER_SIZE	128		//Read
#define BUFFER_SIZE			1024

#define LOGGER_ENABLE		1			//1 - ON, 0 - OFF


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

public:
	Server(const std::string& host, const std::string& pw);

	void createSocket();

};