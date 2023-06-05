#include "irc.hpp"

int err(char *s) {
	cerr << "Error";
	if (s)
		cerr << ": " << s;
	cerr << "\n";
	return 1;
}

int main(int ac, char **av) {
	if (ac != 3)
		return err(const_cast<char *>("# of input arg"));

	try {
		string host		= "127.0.0.1";
		string port		= av[1];
		string password	= av[2];

		int	running =	1;
		int sock	=	create_socket(port);

		(void) sock;

		while (running) {
			cout << sock << "\n";
			running = 0;
		}
	} catch (exception &e) {
		cerr << e.what() << "\n";
	}
}
