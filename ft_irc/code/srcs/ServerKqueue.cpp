/* This code job in BSD System */

#ifdef __APPLE__
	
	#include "ServerKqueue.hpp"

	/* Constructors */
	ServerKqueue::ServerKqueue(int port)
	{
		std::string tmp = "127.0.0.1";
		AbstractServerApi::Init(tmp, port);
		Init_Serv();
	}

	ServerKqueue::ServerKqueue(const char *ipaddr, int port)
	{
		std::string tmp = std::string(ipaddr);;
		AbstractServerApi::Init(tmp, port);
		Init_Serv();
	}

	ServerKqueue::ServerKqueue(std::string ipaddr, int port)
	{
		AbstractServerApi::Init(ipaddr, port);
		Init_Serv();
	}

	void 	ServerKqueue::Init_Serv()
	{
		_logs << "ServerType: Kqueue 🌐 " << std::endl;

		int res_kevent;

		/* 
		** Системный вызов kqueue () создает новую очередь событий ядра и возвращает 
     	** дескриптор 
		*/

		_kq_fd = kqueue();
		if (_kq_fd == -1)
			ServerError("Kqueue");

		/* Добавляю событие прослушки fd сервера */
		/* Задаем события для отслеживания */
		/* EV_SET() — это макрос, предназначенный для упрощения инициализации структуры kevent . */
		/* EVFILT_READ - cобытия , EV_ADD | EV_ENABLE - фильтры его */
		/* Грубо говоря настриваю сокет сервера на прослушивание */
		EV_SET(&_evSet, _server_fd, EVFILT_READ, EV_ADD | EV_ENABLE , 0, 0, NULL);


		/* 
		**  Системный вызов kevent () используется для регистрации событий в очереди и 
		** возврата пользователю любых ожидающих событий. Аргумент списка изменений — это указатель 
		** на массив структур kevent
		*/
		
		res_kevent = kevent(_kq_fd, &_evSet, 1, NULL, 0, NULL);
		if (res_kevent == -1)
			ServerError("Kevent");

		bzero(&_evSet, sizeof(_evSet));
	}



	/*
	**	Simple Use
	*/


	void 	ServerKqueue::kqueue_add(int fd)
	{
		struct kevent kv;
		
		/* EV_ADD -> добавляю в очередь на отслеживание */
		EV_SET(&kv, fd, EVFILT_READ, EV_ADD, 0 , 0, NULL);
		if (kevent(_kq_fd, &kv, 1, NULL, 0, NULL) == -1)
			ServerError("kevent add");

	}

	void 	ServerKqueue::kqueue_remove(int fd)
	{
		struct kevent kv;
		
		/* EV_DISABLE -> удаляю дескриптор из очереди отслеживания */
		EV_SET(&kv, fd, EVFILT_READ, EV_DISABLE, 0 , 0, NULL);
		if (kevent(_kq_fd, &kv, 1, NULL, 0, NULL) == -1)
			ServerError("kevent remove");
		
	}


	void 	ServerKqueue::Start()
	{
		Logger(BLUE, "Wait kevent...");
		bzero(_evList, sizeof(_evList));
		
		struct timespec ts;
		ts.tv_sec = 0;
		ts.tv_nsec = 0;

		_new_events = kevent(_kq_fd, NULL, 0, _evList, KQUEUE_SIZE, NULL);
		if (_new_events == -1)
			ServerError("kevent");


		for (int i = 0; i < _new_events; i++)
		{
			client_fd = _evList[i].ident;

			// When the client disconnects an EOF is sent. By closing the file
			// descriptor the event is automatically removed from the kqueue.
			if (_evList[i].flags & EV_EOF)
			{
				Logger(RED, "Disconnect fd(" + std::to_string(client_fd) + ") ❌ ");				
				kqueue_remove(client_fd);
				RemoveClient(client_fd);
			}
			else if (client_fd == _server_fd)
			{
				printf("i:%d\n", i);
				int new_client_fd;

				new_client_fd = Accept();
				Logger(GREEN, "Connect fd(" + std::to_string(new_client_fd) + ") ✅ ");
				kqueue_add(new_client_fd);
			}
			else if (_evList[i].filter == EVFILT_READ)
			{
				AbstractServerApi::ReadInFd(client_fd);
				//event_flag = EVFILT_READ;
			}
			else if (_evList[i].filter == EVFILT_WRITE)
			{
				//event_flag = EVFILT_WRITE;
			}
		}

	}

	/* Main Functional */
	int		ServerKqueue::WaitEvent()
	{
		Logger(BLUE, "Wait kevent...");
		bzero(_evList, sizeof(_evList));
		
		struct timespec ts;
		ts.tv_sec = 0;
		ts.tv_nsec = 0;

		_new_events = kevent(_kq_fd, NULL, 0, _evList, KQUEUE_SIZE, NULL);
		_last_iter_connect = 0;
		_last_iter_read = 0;
		_last_iter_disconnect = 0;

		if (_new_events == -1)
		{
			ServerError("kevent");
			return (-1);
		}
		return (_new_events);
	}

	int		ServerKqueue::CheckConnect()
	{
		Logger(BLUE, "Check connect...");
		int client_fd;
		int new_client_fd;

		for (int i = _last_iter_connect; i < _new_events; i++)
		{
			client_fd = _evList[i].ident;

			if (client_fd == _server_fd)
			{
				new_client_fd = Accept();
				Logger(GREEN, "Connect fd(" + std::to_string(new_client_fd) + ") ✅ ");
				kqueue_add(new_client_fd);
				
				_last_iter_connect = i;
				return (new_client_fd);
			}
		}
		return (0);
	}

	int		ServerKqueue::CheckDisconnect()
	{
		Logger(BLUE, "Check Disconnect...");
		int client_fd;

		for (int i = _last_iter_disconnect; i < _new_events; i++)
		{
			client_fd = _evList[i].ident;


			if (_evList[i].flags & EV_EOF)
			{
				Logger(RED, "Disconnect fd(" + std::to_string(client_fd) + ") ❌ ");				
				kqueue_remove(client_fd);
				RemoveClient(client_fd);

				_last_iter_disconnect = i;
				return (client_fd);
			}
			
		}
		return (0);
	}
	
	int		ServerKqueue::CheckAndRead()
	{
		Logger(BLUE, "CheckAndRead...");
		int client_fd;
		int res;

		(void)res;

		for (int i = _last_iter_read; i < _new_events; i++)
		{
			client_fd = _evList[i].ident;

			if (_evList[i].filter == EVFILT_READ)
			{
				res = AbstractServerApi::ReadInFd(client_fd);
				//AbstractServerApi::SendInFd(client_fd, std::string("Sucsess in read\n"));
				//event_flag = EVFILT_READ;

				return(client_fd);
				//return (res);
			}
			
		}
		return (0);
	}

	ServerKqueue::~ServerKqueue()
	{
		close(_kq_fd);
		Logger(RED, "Call ServerKqueue Destructor ❌ ");
	}

#endif
