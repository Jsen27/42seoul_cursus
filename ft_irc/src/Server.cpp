#include "../inc/ircserv.hpp"

Server::Server(void) : Command() {}

Server::Server(char *port_to_use, char *pass_to_use) : Command() {
	setPort(port_to_use);
	setPass(pass_to_use);
	init_sock();
	run();
}

Server::Server(const Server &other_serv) : Command() {
	*this = other_serv;
}

Server	&Server::operator=(const Server &other_serv) {
	port = other_serv.port;
	pass = other_serv.pass;
	sock = other_serv.sock;
	stby = other_serv.stby;
	return (*this);
}

Server::~Server(void) {
	if (g_stop == true) {
		for (ssize_t i = (stby.size() - 1); !stby.empty() && i >= 0; i--) {
			close(stby[i].fd);
			stby.erase(stby.begin() + i);
		}
		for (ssize_t i = (clients.size() - 1); !clients.empty() && i >= 0; i--)
			Command::disconnect(i, clients[i].fd);
	}
}

int
Server::getPort(void) const {
	return (port);
}

std::string
Server::getPass(void) const {
	return (pass);
}

int
Server::getSock(void) const {
	return (sock);
}

std::vector<pollfd>
Server::getStby(void) const {
	return (stby);
}

void
Server::setPort(char *port_to_use) {
	size_t		i;
	size_t		port_len = std::strlen(port_to_use);
	int 		nb = std::atoi(port_to_use);

	for (i = 0; port_to_use[i] && std::isdigit(port_to_use[i]); i++);
	if (i != port_len || port_len < 4 || port_len > 5 || nb < PORT_MIN || nb > PORT_MAX) {
		std::string message(RED "The port number must be ");
		if (i != port_len)
			message += "a " UNDER "positive integer\n" RESET;
		else
			message += "between " UNDER "1024 and 65535\n" RESET;
		throw (std::logic_error(message));
	}
	else
		port = static_cast<int>(nb);
}

void
Server::setPass(char *pass_to_use) {
	size_t	i;
	size_t	pass_len = std::strlen(pass_to_use);

	for (i = 0; pass_to_use[i] && !std::isspace(pass_to_use[i]); i++);
	if (i != pass_len)
		throw (std::logic_error(RED "Password must not contain " UNDER "whitespace\n" RESET));
	pass = std::string(pass_to_use);
}

void
Server::init_sock(void) {
	int					opt = 1;
	struct sockaddr_in	serv_addr;
	struct sockaddr		*bind_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);
	bind_addr = reinterpret_cast<struct sockaddr *>(&serv_addr);
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == ERROR)
		throw (std::runtime_error(RED "Failed to create the server socket\n" RESET));
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == ERROR)
		throw (std::runtime_error(RED "Failed to set socket options\n" RESET));
	if (bind(sock, bind_addr, sizeof(serv_addr)) == ERROR)
		throw (std::runtime_error(RED "Failed to bind the server socket to the port\n" RESET));
	if (listen(sock, SOMAXCONN) == ERROR)
		throw (std::runtime_error(RED "Failed to listen on the server socket\n" RESET));
}

void
Server::run(void) {
	int		num_events;
	pollfd	initialClient;
	initialClient.fd = sock;
	initialClient.events = POLLIN;
	clients.push_back(initialClient);

	std::cout << GREEN "Server listening on port " << port << RESET << std::endl;
	while (!clients.empty() && g_stop == false) {
		num_events = poll(clients.data(), clients.size(), TIMEOUT);
		if (num_events == ERROR && g_stop == false)
			throw (std::runtime_error(RED "Failed to create poll file descriptor\n" RESET));
		else if ((clients.size() + stby.size()) <= MAX_CLIENTS && clients[0].revents & POLLIN)
			create_client();
		for (size_t i = 0; !stby.empty() && i < stby.size() && check_pass(i, stby[i].fd) == true; i++)
			init_client(i, stby[i].fd);
		for (size_t i = 1; !clients.empty() && i < clients.size(); i++) {
			std::vector<std::string>	cmd(splity(get_input(i, clients[i].fd, false), ISSPACE));
			if (!cmd.empty())
				display_logs(cmd, i, clients[i].fd);
			if (!cmd.empty() && clients[i].fd != -1)
				Command::exec_command(cmd, i);
		}
	}
}

void
Server::create_client(void) {
	int	newClient_fd;

	newClient_fd = accept(sock, NULL, NULL);
	if (newClient_fd == ERROR)
		std::cerr << RED "Failed to accept new client\n" << RESET;
	else {
		pollfd	newClient;
		newClient.fd = newClient_fd;
		newClient.events = POLLIN | POLLERR | POLLHUP;
		newClient.revents = 0;
		stby.push_back(newClient);
	}
}

bool
Server::check_pass(int i, int cfd) {
	static std::map<int, std::string>	buffer;
	std::vector<std::string>			input;
	int									tmp = cfd;

	buffer[cfd] += " " + get_input(CHECK_PASS, cfd, false);
	if (cfd == -1) {
		stby.erase(stby.begin() + i);
		buffer[tmp].clear();
	}
	else if (!(input = splity(buffer[cfd], ISSPACE)).empty()) {
		std::vector<std::string>::iterator	it(std::find(input.begin(), input.end(), "PASS"));
		if (it != input.end() && (it + 1) != input.end() && *(it + 1) != pass) {
			buffer[cfd].clear();
			stby.erase(stby.begin() + i);
			Command::disconnect(CHECK_PASS, cfd);
		}
		else if (it != input.end() && (it + 1) != input.end() && *(it + 1) == pass) {
			if (create_user(input, cfd) == false)
				return (buffer[cfd].clear(), true);
		}
	}
	return (false);
}

std::string
Server::get_input(int i, int &cfd, bool reset) {
	static std::map<int, std::string>	buffer;

	if (reset == true || buffer[cfd].find('\n') != std::string::npos)
		buffer[cfd].clear();
	if (reset == false) {
		buffer[cfd] += handle_client(i, cfd);
		if (buffer[cfd].find('\n') != std::string::npos)
			return (buffer[cfd]);
	}
	return (EMPTY);
}

std::string
Server::handle_client(int i, int &cfd) {
	char	buffer[BUFFER_SIZE] = {0};
	int		read;

	if (i == CHECK_PASS || (clients[i].revents & POLLIN)) {
		if ((read = recv(cfd, buffer, BUFFER_SIZE, 0)) == ERROR)
			std::cerr << RED "Client " << cfd << " : Failed to receive data\n" RESET;
		else if (read == 0) {
			get_input(i, cfd, true);
			Command::disconnect(i, cfd);
		}
		else
			return (std::string(buffer));
	}
	else if ((clients[i].revents & POLLERR) || (clients[i].revents & POLLHUP)) {
		get_input(i, cfd, true);
		Command::disconnect(i, cfd);
	}
	return (EMPTY);
}

bool
Server::create_user(std::vector<std::string> input, int cfd) {
	std::vector<std::string>::iterator	it;

	users[cfd].cfd = cfd;
	it = std::find(input.begin(), input.end(), "NICK");
	if (it != input.end() && (it + 1) != input.end())
		users[cfd].nick = *(it + 1);
	it = std::find(input.begin(), input.end(), "USER");
	if (it != input.end() && (it + 1) != input.end() && (it + 2) != input.end()) {
		users[cfd].user = *(it + 1);
		users[cfd].host = *(it + 2);
	}
	if (users[cfd].nick.empty() || users[cfd].user.empty() || users[cfd].host.empty()) {
		users[cfd].nick.clear();
		users[cfd].user.clear();
		users[cfd].host.clear();
		return (true);
	}
	return (false);
}

void
Server::init_client(int i, int cfd) {
	clients.push_back(stby[i]);
	std::string message = "SUCCESS : Welcome!!\r\n"; //??
	if (send(cfd, message.c_str(), message.length(), 0) == ERROR)
		std::cerr << RED "Client " << cfd << SEND_ERROR RESET;
	// message = users[cfd].nick + " : !";
	// Command::send_code(message, cfd);
	// std::string codes[5] = {"002", "003", "004", "005", "375"};
	// for (int j(0); j < 5; j++)
	// 	Command::send_code(codes[j], EMPTY, cfd);
	// Command::send_code("Welcome!!", cfd);
	// Command::send_code("376", EMPTY, cfd);
	std::cout << YELLOW "--------------------------------------------------\n";
	std::cout << "Client " << cfd << " : Connected\n";
	std::cout << "Nickname : " << users[cfd].nick << std::endl;
	std::cout << "Username : " << users[cfd].user << std::endl;
	std::cout << "--------------------------------------------------\n" RESET;
	stby.erase(stby.begin() + i);
}

void
Server::display_logs(std::vector<std::string> &cmd, int i, int cfd) {
	std::vector<std::string>::iterator	it;

	if (cfd != -1) {
		for (size_t j(0); j < cmd[0].size(); j++)
			cmd[0][j] = std::tolower(cmd[0][j]);
		for (it = cmd.begin(); it != cmd.end()&& *it != "quit" && *it != "privmsg" ; ++it);
		if (it != cmd.end() && *it == "quit") {
			get_input(i, cfd, true);
			Command::disconnect(i, cfd);
		}
		else if (it == cmd.end()) {
			std::cout << CYAN "Client " << cfd << " (" << users[cfd].nick;
			std::cout << "~" << users[cfd].user << ") : ";
			for (std::vector<std::string>::iterator it = cmd.begin(); it != cmd.end(); ++it)
				std::cout << *it << ' ';
			std::cout << RESET << std::endl;
		}
	}
	else
		std::cerr << RED "Connection lost with a client\n" RESET;
}
