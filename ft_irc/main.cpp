#include "Server.hpp"

Server serv(0, "");

void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		std::map<int, User>::iterator it = serv.getList().begin();
		std::map<int, User>::iterator ite = serv.getList().end();
		std::cout << std::endl;
		std::cout << "Server close!" << std::endl;
		for(int i = 0; it != ite && i < serv.getList().size(); it++, i++)
		{
			serv.sendData((*it).first, "DISCONNECTED\r\n");
			close((*it).first);
		}
		close(serv.getServerSock());
		exit(0);
	}
}

int	main(int ac, char **av)
{
	signal(SIGINT, sig_handler);
	if (init(ac, av, serv))
		return (1);
	if (cycle(serv))
		return (1);
	return (0);
}