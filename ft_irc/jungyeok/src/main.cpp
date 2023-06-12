#include "network/Server.hpp"

int main(int ac, char **av) {
	if (ac != 3)
		throw std::runtime_error("Put ./ircserv <port> <password>");

	Server	server(av[1], av[2]);

	try {
		server.start();
		return 0;
	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
}
