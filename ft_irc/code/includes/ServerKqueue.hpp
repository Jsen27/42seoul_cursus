#ifndef SERVER_KQUEUE
# define SERVER_KQUEUE
#ifdef __APPLE__

/* Abstract Class  */
#include "ServerApi.hpp"
#include "Color.hpp"
#include <iostream>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>


#define 		KQUEUE_SIZE 64


class ServerKqueue: public AbstractServerApi
{
	public:

		/* Constructor */
		ServerKqueue(int port);
		ServerKqueue(std::string ipaddr, int port);
		ServerKqueue(const char *ipaddr, int port);
		
		/* Simple Use */
		void Start();

		/* Main Functional*/
		int		WaitEvent();
		int		CheckConnect();
		int		CheckDisconnect();
		int		CheckAndRead();


		/* Destructor */
		virtual ~ServerKqueue();


	private:
		/* Init */
		void 	Init_Serv();

		/* Help Function */
		void 	kqueue_add(int fd);
		void 	kqueue_remove(int fd);


		
		int	 			_new_events;
		int				client_fd;

		/* Для макроса */
		struct kevent 	_evSet;
		struct kevent 	_evList[KQUEUE_SIZE];

		/* Очередь (дескриптор) */
		int			_kq_fd;
};

#endif
#endif