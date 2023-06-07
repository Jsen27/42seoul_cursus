
#ifndef SERVER_POLL
#define SERVER_POLL

#include "ServerApi.hpp"
#include <poll.h>		/* poll */

#include <vector>

class ServerPoll: public AbstractServerApi
{
	public:

		/* Constructor */
		ServerPoll(int port);
		ServerPoll(std::string &ipaddr, int port);
		ServerPoll(const char *ipaddr, int port);

		/* Simple use */
		void Start();

		/* Main Functional*/
		int		WaitEvent();
		int		CheckConnect();
		int		CheckDisconnect();
		int		CheckAndRead();

		
		/* Destructor */
		virtual ~ServerPoll();

	private:
		/* Client fds */
		std::vector<struct pollfd> _pollfds;

		/* Init Serv */
		void 	Init_Serv();

		/* Help Function */
		void 	poll_add(int fd, short events);
		void 	poll_remove(int fd);
		int 	check_disconnect(int fd);


		// void 	AddFd(int fd);
		// void	RemoveFd(int client_fd);
};

#endif