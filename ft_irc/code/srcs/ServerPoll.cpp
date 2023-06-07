/* This code job in UNIX System */
#include "ServerPoll.hpp"

/* Constructors */
ServerPoll::ServerPoll(int port)
{
	std::string tmp = "127.0.0.1";
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}

ServerPoll::ServerPoll(const char *ipaddr, int port)
{
	std::string tmp = std::string(ipaddr);;
	AbstractServerApi::Init(tmp, port);
	Init_Serv();
}

ServerPoll::ServerPoll(std::string& ipaddr, int port)
{
	AbstractServerApi::Init(ipaddr, port);
	Init_Serv();
}

void ServerPoll::Init_Serv()
{
	_logs << "ServerType: Poll 🌐 " << std::endl;

	struct pollfd fd_serv;

	fd_serv.fd = _server_fd;
	fd_serv.events = POLLIN;	/* Какие события отслеживаю (входящие)*/
	fd_serv.revents = 0;

	_pollfds.push_back(fd_serv);
}


/* 
** Simple Use
*/

/* Help Function */
void 	ServerPoll::poll_add(int fd, short events)
{
	struct pollfd fd_client;

	fd_client.fd = fd;
	fd_client.events = events;	//говорю какие события слушаюй
	fd_client.revents = 0;
	_pollfds.push_back(fd_client);
}

void 	ServerPoll::poll_remove(int fd)
{
	(void)fd;
}


int 	ServerPoll::check_disconnect(int fd)
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


void ServerPoll::Start()
{
	Logger(BLUE, "Wait Event...");

	int result;
	int timeout = -1;

	/* Массив дискрипторов и размер его*/
	result = poll(& _pollfds[0], _pollfds.size(), timeout);
	Logger(B_GRAY, "Poll return " + std::to_string(result));
	
	if (result == -1)
	{
		ServerError("Poll: ");
	}
	else if (result == EINVAL)
	{
		Logger(RED, "TimeOut 🕐 ");
	}
	else
	{
		int 				client_fd;

		/* Check connect*/
		if( _pollfds[0].revents != 0)
		{
			client_fd = Accept();
			if (client_fd < 0)
			{
				if (errno != EWOULDBLOCK)
					ServerError("Accept");
			}
			else
			{// add fd
				AbstractServerApi::SetNonBlockingFd(client_fd);
				poll_add(client_fd, POLLIN);
			}
		}
		else
		{
			int fd_read;

			fd_read = 0;
			/* Read */
			Logger(BLUE, "Check read...");
			std::vector<struct pollfd>::iterator	it = _pollfds.begin();
			std::vector<struct pollfd>::iterator	it_end = _pollfds.end();

			while (it != it_end)
			{
				if (it->fd == _server_fd || it->revents  == 0)
				{
					it++;
					continue;
				}
				fd_read = it->fd;
				Logger(GREEN, "Readble is ready: fd(" + std::to_string(fd_read) + ") ✅ ");
				break;
			}

			if (fd_read != 0)
			{
				int check_res = check_disconnect(fd_read);
				
				if (check_res == 1)
				{
					Logger(RED, "Disconnect fd(" + std::to_string(fd_read) + ") ❌ ");
					Logger(B_GRAY, "Remove fd " + std::to_string(fd_read));
					
					RemoveClient(it->fd);
					close(it->fd);
					_pollfds.erase(it);
				}
				else
				{
					AbstractServerApi::ReadInFd(fd_read);
				}
			}

		}
	}
}



/* Main Functional */
int	ServerPoll::WaitEvent()
{
	Logger(BLUE, "Wait Event...");


	int result;
	int timeout = -1;

	InitVariable();

	/* Массив дискрипторов и размер его*/
	result = poll(& _pollfds[0], _pollfds.size(), timeout);
	Logger(B_GRAY, "Poll return " + std::to_string(result));
	
	if (result == -1)
	{
		ServerError("Poll: ");
	}
	else if (result == EINVAL)
	{
		Logger(RED, "TimeOut 🕐 ");
	}
	return (result);
}


int		ServerPoll::CheckConnect()
{
	Logger(BLUE, "Check connect ");
	
	int 				client_fd;

	/* Check connect*/
	if( _pollfds[0].revents != 0)
	{
		client_fd = Accept();
		if (client_fd < 0)
		{
			if (errno != EWOULDBLOCK)
				ServerError("Accept");
		}
		else
		{
			AbstractServerApi::SetNonBlockingFd(client_fd);
			poll_add(client_fd, POLLIN);
			return (client_fd);
		}
	}
	return (0);
}

int		ServerPoll::CheckDisconnect()
{
	int 	res;
	int 	fd_read;
	int 	i = 0;
	int 	j = 0;

	fd_read = 0;
	/* Read */
	Logger(BLUE, "Check Disconnect...");
	std::vector<struct pollfd>::iterator	it = _pollfds.begin();
	std::vector<struct pollfd>::iterator	it_end = _pollfds.end();

	
	while (it != it_end)
	{
		while (i < _last_iter_disconnect)
		{
			i++;
			j++;
			it++;
		}

		if (it->fd == _server_fd || it->revents  == 0)
		{
			it++;
			j++;
			continue;
		}

		_last_iter_disconnect = j;

		fd_read = it->fd;
		break;
	}
	if (it == it_end)
		return (0);

	res = check_disconnect(fd_read);

	if (res == 1)
	{
		Logger(RED, "Disconnect fd(" + std::to_string(fd_read) + ") ❌ ");
		Logger(B_GRAY, "Remove fd " + std::to_string(fd_read));
		
		RemoveClient(it->fd);
		close(it->fd);
		_pollfds.erase(it);
		return (fd_read);
	}
	return (res);
}


int		ServerPoll::CheckAndRead()
{
	int 	fd_read;
	int 	res;
	int 	i = 0;
	int 	j = 0;

	fd_read = 0;
	/* Read */
	Logger(BLUE, "Check read...");
	std::vector<struct pollfd>::iterator	it = _pollfds.begin();
	std::vector<struct pollfd>::iterator	it_end = _pollfds.end();

	
	while (it != it_end)
	{
		while (i < _last_iter_read)
		{
			i++;
			j++;
			it++;
		}

		if (it->fd == _server_fd || it->revents  == 0)
		{
			it++;
			j++;
			continue;
		}

		_last_iter_read = j;

		fd_read = it->fd;
		break;
	}
	if (it == it_end)
		return (0);
		
	res = AbstractServerApi::ReadInFd(fd_read);
	if (res == 1)
	{
		//AbstractServerApi::SendInFd(fd_read, std::string("Sucsess in read\n"));
		return (fd_read);
	}
	return (res);
}

/* Destructor */
ServerPoll::~ServerPoll()
{
	Logger(RED, "Call ServerPoll Destructor ❌ ");	
}