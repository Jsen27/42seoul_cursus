/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ServerApi.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifanzilka <ifanzilka@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:49:56 by bmarilli          #+#    #+#             */
/*   Updated: 2022/09/26 03:13:33 by ifanzilka        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_API
# define SERVER_API

#include "Color.hpp"

#include <netinet/in.h> /* struct sockaddr_in */
#include <arpa/inet.h>	/* inet_addr inet_htop */
#include <sys/socket.h>	/* socket */
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

#include "ClientIrc.hpp"	/* Client */

#define SERVER_PROTOCOL 	AF_INET 	//IpV4
#define	SERVER_TYPE			SOCK_STREAM //TCP
#define MAX_CONNECT_LISTEN 	15			//In Listen
#define	BUFFER_SIZE_SEND	1024		//Send
#define RECV_BUFFER_SIZE	128		//Read
#define BUFFER_SIZE			1024


#define LOGGER_ENABLE		1			//1 - ON, 0 - OFF


class AbstractServerApi
{
	public:

		/* Virtual i talk mast have in realizate */

		virtual	int		WaitEvent() = 0;
		virtual	int		CheckConnect() = 0;
		virtual	int		CheckDisconnect() = 0;
		virtual	int		CheckAndRead() = 0;

		std::string			GetHostName();
		int					GetPort();
		void				PrintSockaddrInfo(struct sockaddr_in *info);
		int					SetNonBlockingFd(int fd);
		ClientIrc* 			GetClientFromFd(int fd);

		void			Logger(std::string color,std::string msg);

		/* Main Functional */
		//virtual void 				Run() = 0;


		/* MSG in READ */
		std::string 		_msg;


		/* Destructor */
		virtual				 ~AbstractServerApi();

	protected:
		/* Настройка моей сети */
		struct sockaddr_in 	_servaddr;
		std::string 		_ipaddr;
		std::ofstream 		_logs;
		int 				_port;
		int 				_server_fd;
		int					_fd_log_file;





		/* Helper */
		int 				_last_iter_connect;
		int 				_last_iter_disconnect;
		int 				_last_iter_read;

	public:
		/* Говорю что можно переопределить */
		virtual	void		Init(std::string& ipaddr, int port);
		virtual	void		InitVariable();
		virtual int 		Create_socket();
		virtual int 		Binded();
		virtual int 		Listen();
		virtual	int 		Accept();
		virtual	int 		ReadInFd(int fd);
		virtual	int 		SendInFd(int fd, std::string msg);
		virtual	int 		SendInFd(int fd, const char *msg);
		virtual	int			SendInFd(int fd, const char *msg, size_t size);



		/* Help function */
		void GetNameInfo(const sockaddr *);
		void PrintHostName(void);

		/* Print Errno */
		virtual	void	ServerError(const char *s);

		/* Clients */
		std::vector<ClientIrc*> _Clients;

		/* Add new  Client */
		void 	AddClient(int fd_client, sockaddr_in 	addrinfo_client, std::string server_ipaddr);
		
		/* Remove */
		void 	RemoveClient(int fd_client);

};

#endif