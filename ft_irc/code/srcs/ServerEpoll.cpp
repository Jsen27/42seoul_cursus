/* This code job in linux System */
#ifdef __linux__
#include "ServerEpoll.hpp"

/* Constructors */
void ServerEpoll::Init_Serv()
{
	_logs << "ServerType: Epoll 🌐 " << std::endl;
	int res;

	struct epoll_event event;
	event.data.fd = _server_fd;
  	event.events = EPOLLIN | EPOLLET; /* Отслеживаю чтение и */

	/* Создаем очеред */
	_epfd = epoll_create(MAX_EVENTS);
	
	if (_epfd == -1)
		ServerError("Epoll_create");
	
	/*  Добавляю fd в очередь epfd чтобы мог отслеживать его события*/
	res = epoll_ctl(_epfd, EPOLL_CTL_ADD, _server_fd, &event);
	if (res == -1)
		ServerError("Epoll Init epoll_ctl");
	

}

ServerEpoll::ServerEpoll(int port)
{
	std::string tmp = "127.0.0.1";
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}

ServerEpoll::ServerEpoll(std::string& ipaddr, int port)
{
	AbstractServerApi::Init(ipaddr, port);
	Init_Serv();
}

ServerEpoll::ServerEpoll(const char *ipaddr, int port)
{
	std::string tmp = std::string(ipaddr);;
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}




/* Simple Use */

/* Help function */

void ServerEpoll::epoll_add(int fd, uint32_t events)
{
	struct epoll_event ev;
	
	ev.events = events;
	ev.data.fd = fd;
	
	if (epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev) == -1)
	{
		ServerError("Epoll_ctl add");
	}
}


void ServerEpoll::Start()
{
	Logger(BLUE, "Wait epoll_wait...");
	
	int n_events;
	int timeout;

	timeout = -1;
	n_events = epoll_wait(_epfd, _events, EPOLL_SIZE, timeout);

	for (int i = 0; i < n_events; i++)
	{
		if (_events[i].data.fd == _server_fd)
		{

			int client_fd = Accept();
			if (client_fd < 0)
			{
				ServerError("Accept");
			}
			else
			{
				AbstractServerApi::SetNonBlockingFd(client_fd);
				epoll_add(client_fd,  EPOLLIN | EPOLLET | EPOLLRDHUP | EPOLLHUP);
				
			}
			
		} 
		else if (_events[i].events & EPOLLIN)
		{
			/* handle EPOLLIN event */
			//printf("POLLIN");
			//int rc;
			//char buffer[1024];

			//bzero(buffer, 1024);
			//size_t bytes_rea = recv(_events[i].data.fd, buffer, sizeof(buffer), 0);
			//printf("read %zu bytes\n", bytes_rea);
			//Logger(GREEN, std::to_string(_events[i].data.fd) + " message:\n" + std::string(buffer));
			//send(_events[i].data.fd, "Message Sucsefull", 17, 0);
			AbstractServerApi::ReadInFd(_events[i].data.fd);

		} 
		else
		{
			printf("[+] unexpected\n");
		}

		if (_events[i].events & (EPOLLRDHUP | EPOLLHUP))
		{
				Logger(RED, std::to_string(_events[i].data.fd) + " Connection close ❌");
				epoll_ctl(_epfd, EPOLL_CTL_DEL, _events[i].data.fd, NULL);
				RemoveClient(_events[i].data.fd);
				close(_events[i].data.fd);
				continue;
		}
	}
}


/* Main Functional */
int		ServerEpoll::WaitEvent()
{
	Logger(BLUE, "Wait epoll_wait...");
	
	//int n_events;
	int timeout;

	timeout = -1;
	_new_events = epoll_wait(_epfd, _events, EPOLL_SIZE, timeout);
	InitVariable();

	if (_new_events == -1)
	{
		ServerError("epoll_wait");
		return (-1);
	}
	return (_new_events);
}

int		ServerEpoll::CheckConnect()
{
	Logger(BLUE, "Check connect...");
	//int client_fd;
	//int new_client_fd;

	for (int i = _last_iter_connect; i < _new_events; i++)
	{
		if (_events[i].data.fd == _server_fd)
		{

			int client_fd = Accept();
			if (client_fd < 0)
			{
				ServerError("Accept");
				return (-1);
			}
			else
			{
				AbstractServerApi::SetNonBlockingFd(client_fd);
				epoll_add(client_fd,  EPOLLIN | EPOLLET | EPOLLRDHUP | EPOLLHUP);
				_last_iter_connect = i;
				return	(client_fd);
			}
		} 
	}
	return (0);
}

int		ServerEpoll::CheckDisconnect()
{
	Logger(BLUE, "Check Disconnect...");
	//int client_fd;


	for (int i = _last_iter_connect; i < _new_events; i++)
	{
		
		if (_events[i].events & (EPOLLRDHUP | EPOLLHUP))
		{
				Logger(RED, std::to_string(_events[i].data.fd) + " Connection close ❌");
				epoll_ctl(_epfd, EPOLL_CTL_DEL, _events[i].data.fd, NULL);
				RemoveClient(_events[i].data.fd);
				close(_events[i].data.fd);
				_last_iter_disconnect = i;
				return (_events[i].data.fd);
				//return (1);
		}
		
	}
	return (0);
}
	
int		ServerEpoll::CheckAndRead()
{
	Logger(BLUE, "CheckAndRead...");
	

	for (int i = _last_iter_read; i < _new_events; i++)
	{
		if (_events[i].events & EPOLLIN && _events[i].data.fd != _server_fd)
		{
			AbstractServerApi::ReadInFd(_events[i].data.fd);
			_last_iter_read = i;
			//if (res == 1)
			//	AbstractServerApi::SendInFd(_events[i].data.fd, std::string("Sucsess in read\n"));
			
			return (_events[i].data.fd);
			//return (res);
		}
		
	}
	
	return (0);
}


/* Destructor */
ServerEpoll::~ServerEpoll()
{
	close(_epfd);
	Logger(RED, "Call ServerEpoll Destructor ❌ ");
}


#endif