/* This code job in UNIX System */
#include <ServerSelect.hpp>

/* 
** Constructor
*/

void ServerSelect::Init_Serv()
{
	_logs << "ServerType: Select 🌐 " << std::endl;

	_max_fd = _server_fd;

	/* Чищу множество */
	FD_ZERO(&_currfds);
    FD_ZERO(&_writefds);
	/* Добавил во множество */
	FD_SET(_server_fd, &_currfds);
}

ServerSelect::ServerSelect(int port)
{
	std::string tmp = "127.0.0.1";
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}

ServerSelect::ServerSelect(std::string& ipaddr, int port)
{
	AbstractServerApi::Init(ipaddr, port);
	Init_Serv();
}

ServerSelect::ServerSelect(const char *ipaddr, int port)
{
	std::string tmp = std::string(ipaddr);;
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}


/*
** Main Functional
*/







/* 
** Simple Use
*/


void 	ServerSelect::select_add(int fd)
{
	FD_SET(fd, &_currfds);
	_max_fd = fd > _max_fd ? fd : _max_fd;
}

void 	ServerSelect::select_remove(int fd)
{
	close(fd);
	FD_CLR(fd, &_currfds);
}

void ServerSelect::Start()
{
	struct timeval 	time;
	int 			_select;

	time.tv_sec = 0;
	time.tv_usec = 0;

	/* Множества приравниваю */
	_writefds = _readfds = _currfds;
	Logger(BLUE, "Wait select...");

	/* Останавливаю процесс для отловки событий */
	_select = select(_max_fd + 1, &_readfds, NULL, NULL, NULL);
	Logger(B_GRAY, "Select signal is " + std::to_string(_select));

	/*  Error */
	if (_select == -1)
	{
		AbstractServerApi::ServerError("Select -1");
	}
	else if (_select == 0) 
	{
		/* TimeOut in Select */
		Logger(RED, "TimeOut Select ");
		//return (0);
	}
	else
	{
		int client_fd;
		
		/* Check new client */
		if (FD_ISSET(_server_fd, &_readfds))
		{
			client_fd = AbstractServerApi::Accept();
			if (client_fd > 0)
			{
				AbstractServerApi::SetNonBlockingFd(client_fd);
				select_add(client_fd);
			}
			return;
		}

		for (int i = 0; i < _max_fd + 1; i++)
		{

			if (FD_ISSET(i, &_readfds))
			{
				
				int res_read = AbstractServerApi::ReadInFd(i);
				
				if (res_read == 0)
				{
					
					Logger(RED, std::to_string(i) + " Connection close ❌");
					RemoveClient(i);
					select_remove(i);
					return;
				}
				
			}
		}
	}
}


int 	ServerSelect::check_disconnect(int fd)
{
	char c;
	
	int res = recv(fd, &c, 1, 0);

	if (res == 0)
	{
		return (1);
	}
	_msg += &c;
	return (0);
}

/* Main Functional */
int		ServerSelect::WaitEvent()
{
	struct timeval 	time;
	int 			_select;

	time.tv_sec = 0;
	time.tv_usec = 0;

	/* Множества приравниваю */
	_writefds = _readfds = _currfds;
	Logger(BLUE, "Wait select...");

	/* Останавливаю процесс для отловки событий */
	_select = select(_max_fd + 1, &_readfds, NULL, NULL, NULL);
	Logger(B_GRAY, "Select signal is " + std::to_string(_select));
	_last_iter_disconnect = 0;
	_last_iter_connect = 0;
	_last_iter_read = 0;

	/*  Error */
	if (_select == -1)
	{
		AbstractServerApi::ServerError("Select -1");
		return (-1);
	}
	else if (_select == 0) 
	{
		/* TimeOut in Select */
		Logger(RED, "TimeOut Select ");
		return (0);
	}
	else
	{
		return (_select);
	}
}

int		ServerSelect::CheckConnect()
{
	Logger(BLUE, "Check connect...");

	int client_fd;
	
	/* Check new client */
	if (FD_ISSET(_server_fd, &_readfds))
	{
		client_fd = AbstractServerApi::Accept();
		if (client_fd > 0)
		{
			AbstractServerApi::SetNonBlockingFd(client_fd);
			select_add(client_fd);
		}
		return (client_fd);
	}
	return (0);
}

int		ServerSelect::CheckDisconnect()
{
	Logger(BLUE, "Check Disconnect...");
	int res;
	int fd_close;

	fd_close = 0;
	for (int i = _last_iter_disconnect; i < _max_fd + 1; i++)
	{

		if (FD_ISSET(i, &_readfds))
		{
			

			res = check_disconnect(i);
			if (res == 1)
			{
				Logger(RED, std::to_string(i) + " Connection close ❌");
				RemoveClient(i);
				select_remove(i);
				_last_iter_disconnect = i;

				fd_close = i;
			}

		}
	}

	return (fd_close);
}

int		ServerSelect::CheckAndRead()
{
	Logger(BLUE, "Check read...");

	for (int i = _last_iter_read; i < _max_fd + 1; i++)
	{

		if (FD_ISSET(i, &_readfds))
		{
			
			//int res_read = AbstractServerApi::ReadInFd(i);
			AbstractServerApi::ReadInFd(i);
			_last_iter_read = i;
			return (i);
		}
	}

	return (0);
}


/*
** Destructor
*/

ServerSelect::~ServerSelect()
{
	Logger(RED, "Call ServerSelect Destructor❌ ");
}