#ifndef IRC_HPP
# define IRC_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <stdexcept>

// socket, setsockopt, getsockname, bind, connect, listen, accept, send, recv
# include <sys/socket.h>

// getprotobyname, gethostbyname, getaddrinfo, freeaddrinfo
# include <netdb.h>

// htons, htonl, ntohs, ntohl, inet_addr, inet_ntoa
# include <arpa/inet.h>

// signal
# include <signal.h>

// lseek
# include <unistd.h>

// fstat
# include <sys/stat.h>

// fcntl
# include <fcntl.h>

// poll
# include <poll.h>

using namespace std;

#define MAX_CONNECTIONS 16

int create_socket(string port);

#endif
