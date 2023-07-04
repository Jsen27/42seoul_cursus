#include "../inc/ircserv.hpp"

bool	g_stop = false;

std::vector<std::string>
splity(std::string str, const char *delim) {
	char						*buffer;
	std::string					strCpy(str);
	std::vector<std::string>	tab;

	buffer = std::strtok(&strCpy[0], delim);
	while (buffer != NULL) {
		tab.push_back(buffer);
		buffer = std::strtok(NULL, delim);
	}
	return (tab);
}

static void
handle_sigint(int signum) {
	(void)signum;
	g_stop = true;
	std::cout << std::endl;
}

int
main(int ac, char **av) {
	std::signal(SIGINT, handle_sigint);
	std::signal(SIGQUIT, SIG_IGN);
	std::signal(SIGPIPE, SIG_IGN);

	try {
		if (ac != 3)
			throw std::runtime_error("./ircserv <port> <password>");
		std::cout << "\n           _       _           _          \n";
		std::cout << " _ __ ___ (_)_ __ (_)         (_)_ __ ___ \n";
		std::cout << "| '_ ` _ \\| | '_ \\| |         | | '__/ __|\n";
		std::cout << "| | | | | | | | | | |         | | | | (__ \n";
		std::cout << "|_| |_| |_|_|_| |_|_|  _____  |_|_|  \\___|\n";
		std::cout << "                      |_____|             \n\n";

		Server ircserv(av[1], av[2]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
