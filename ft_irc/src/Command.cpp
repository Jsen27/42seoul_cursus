#include "../inc/ircserv.hpp"

Command::Command(void) {}

Command::Command(const Command &other) {
	*this = other;
}

Command	&Command::operator=(const Command &other) {
	clients = other.clients;
	users = other.users;
	channels = other.channels;
	return (*this);
}

Command::~Command(void) {}

std::vector<pollfd>
Command::getClients(void) const {
	return (clients);
}

std::map<int, t_user>
Command::getUsers(void) const {
	return (users);
}

std::map<std::string, t_chan>
Command::getChannels(void) const {
	return (channels);
}

void
Command::exec_command(std::vector<std::string> cmd, int i) {
	if (cmd[0] == "oper" && cmd.size() == 3)
		oper(cmd[1], cmd[2], clients[i].fd);
	else if (cmd[0] == "nick")
		nick(cmd, clients[i].fd);
	else if (cmd[0] == "ping")
		pong(cmd, clients[i].fd);
	else if (cmd[0] == "privmsg")
		privmsg(cmd, clients[i].fd);
	else if (cmd[0] == "mode")
		mode(cmd, clients[i].fd);
	else if (cmd[0] == "join")
		join(cmd, clients[i].fd);
	else if (cmd[0] == "part")
		part(cmd, clients[i].fd);
	else if (cmd[0] == "kick")
		kick(cmd, clients[i].fd);
	else if (cmd[0] == "topic")
		topic(cmd, clients[i].fd);
	else if (cmd[0] == "invite")
		invite(cmd, clients[i].fd);
}

void
Command::send_code(std::string message, int cfd) {
	message = message + "\r\n";
	if (send(cfd, message.c_str(), message.length(), 0) == ERROR)
		std::cerr << RED "Client " << cfd << SEND_ERROR RESET;
}

void
Command::pong(std::vector<std::string> cmd, int cfd) {
	std::string	message = "PONG " + cmd[1] + "\r\n";
	if (send(cfd, message.c_str(), message.length(), 0) == ERROR)
		std::cerr << RED "Client " << cfd << SEND_ERROR << RESET;
}

void
Command::disconnect(int i, int &cfd) {
	if (clients.empty() && i != CHECK_PASS)
		return ;
	else if (i > 0)
		std::cout << RED "Client " << cfd << " : Disconnected\n" RESET;
	if (i != CHECK_PASS) {
		std::map<int, t_user>::iterator it(users.find(cfd));
		clients.erase(clients.begin() + i);
		if (it != users.end())
			users.erase(it);
	}
	close(cfd);
	cfd = -1;
}

void
Command::oper(std::string user, std::string password, int cfd) {
	if (users[cfd].g_oper == false) {
		if (user != ADMIN_USER) {
			send_code(users[cfd].nick + " : Wrong username", cfd);
			std::cout << YELLOW "Client " << cfd << " : Tried to become an operator\n";
			return ;
		}
		if (password != ADMIN_PASS) {
			send_code(users[cfd].nick + " : Wrong password", cfd);
			std::cout << YELLOW "Client " << cfd << " : Tried to become an operator\n";
			return ;
		}
		users[cfd].g_oper = true;
		send_code(users[cfd].nick + " : You are now an oper", cfd);
		std::cout << YELLOW "Client " << cfd << " : Is now an operator\n";
	}
}

void	Command::nick(std::vector<std::string> cmd, int cfd) {
	for (std::map<int, t_user>::iterator it = users.begin(); it != users.end(); ++it) {
		if (it->second.nick == cmd[1]) {
			std::string	message = " " + cmd[1] + " Already in use";
			send_code(message, cfd);
			return ;
		}
	}
	std::string	message = ":" + users[cfd].nick + "!" + users[cfd].user + "NICK " + cmd[1] + "\r\n";
	if (send(cfd, message.c_str(), message.length(), 0) == ERROR)
		std::cerr << RED "Client " << cfd << SEND_ERROR << RESET;
	users[cfd].nick = cmd[1];

}

int	Command::user_inchan(std::string chan, int cfd) {
	for (size_t j = 0; j < channels[chan].chan_users.size(); j++) {
		if (users[cfd].nick == channels[chan].chan_users[j]->nick)
			return (j);
	}
	return (-1);
}

bool	Command::oper_inchan(std::string chan, int cfd) {
	for (size_t j = 0; j < channels[chan].chan_users.size(); j++) {
		if (users[cfd].nick == channels[chan].chan_users[j]->nick) {
			for (size_t i = 0; i < channels[chan].chan_operators.size(); i++) {
				if (cfd == channels[chan].chan_operators[i])
					return (true);
			}
			break ;
		}
	}
	return (false);
}

bool
Command::user_invited(std::string chan, int cfd) {
	for (size_t j = 0; j < channels[chan].chan_invitees.size(); j++) {
		if (users[cfd].nick == channels[chan].chan_invitees[j])
			return (true);
	}
	return (false);
}

void
Command::topic(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 2) {
		send_code(EMPTY, cfd);
		return ;
	}
	std::map<std::string, t_chan>::iterator	it;
	std::string	msg;
	it = channels.find(cmd[1]);
	if (it != channels.end()) {
		if (user_inchan(cmd[1], cfd) == -1) {
			send_code(cmd[1] + " :You're not on that channel", cfd);
			return ;
		}
		if (cmd.size() < 3) {
			if (channels[cmd[1]].chan_topic.empty()) {
				send_code(cmd[1] + " :No topic is set", cfd);
				return ;
			}
			send_code(cmd[1] + " The topic is " + channels[cmd[1]].chan_topic, cfd);
			send_code(EMPTY, cfd);
			return ;
		}
		else if (!oper_inchan(cmd[1], cfd) && channels[cmd[1]].mode_topic) {
			send_code(cmd[1] + " :You're not channel operator", cfd);
			return ;
		}
		if (cmd[2].size() == 1 && cmd[2][0] == ':')
			channels[cmd[1]].chan_topic = EMPTY;
		else
			channels[cmd[1]].chan_topic = cmd[2];
		for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++) {
			// msg = ":" + channels[cmd[1]].chan_users[i]->nick + "!" + channels[cmd[1]].chan_users[i]->user; ////////////////////////
			msg = "TOPIC " + cmd[1] + " " + channels[cmd[1]].chan_topic + "\r\n";
			if (send(channels[cmd[1]].chan_users[i]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << channels[cmd[1]].chan_users[i]->cfd << SEND_ERROR << RESET;
		}
	}
	else
		send_code(" " + cmd[1] + " :No such channel", cfd);
}

void
Command::privmsg(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 3)
		return ;

	std::map<std::string, t_chan>::iterator	it;
	bool	joined = false;

	std::string	msg = ":" + users[cfd].nick + "!" + users[cfd].user;
	msg += "PRIVMSG " + cmd[1];
	for (size_t i = 2; i < cmd.size(); i++)
		msg += " " + cmd[i];
	msg += "\r\n";
	it = channels.find(cmd[1]);
	if (it != channels.end()) {
		for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++) {
			if (channels[cmd[1]].chan_users[i]->cfd == cfd) {
				joined = true;
				break ;
			}
		}
		if (!joined)
			return ;
		for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++) {
			if (channels[cmd[1]].chan_users[i]->cfd == cfd)
				continue ;
			if (send(channels[cmd[1]].chan_users[i]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << channels[cmd[1]].chan_users[i]->cfd << SEND_ERROR << RESET;
		}
		return ;
	}
	for (size_t i = 0; i < users.size(); i++) {
		if (users[i].nick == cmd[1]) {
			if (send(users[i].cfd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << users[i].cfd << SEND_ERROR << RESET;
			return ;
		}
	}
}

void
Command::kick(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 3)
		return ;
	std::map<std::string, t_chan>::iterator it;
	it = channels.find(cmd[1]);
	if (it == channels.end())
		return ;
	if (!oper_inchan(cmd[1], cfd)) {
		send_code(" " + cmd[1] + " :You're not channel operator", cfd);
		return ;
	}
	for (size_t j = 0; j < channels[cmd[1]].chan_users.size(); j++)
	{
		if (channels[cmd[1]].chan_users[j]->nick == cmd[2])
		{
			std::string msg = ":" + users[cfd].nick + "!" + users[cfd].user + "KICK " + cmd[1] + " " + cmd[2] + "\r\n";
			for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++)
			{
				if (send(channels[cmd[1]].chan_users[i]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
					std::cerr << RED "Client " << channels[cmd[1]].chan_users[i]->cfd << SEND_ERROR << RESET;
			}
			std::vector<int>::iterator vit = find(channels[cmd[1]].chan_operators.begin(), channels[cmd[1]].chan_operators.end(), channels[cmd[1]].chan_users[j]->cfd);
			if (vit != channels[cmd[1]].chan_operators.end())
				channels[cmd[1]].chan_operators.erase(vit);
			channels[cmd[1]].chan_users.erase(channels[cmd[1]].chan_users.begin() + j);
			break ;
		}
	}
}

void
Command::invite(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 3) {
		send_code(EMPTY, cfd);
		return ;
	}
	std::map<std::string, t_chan>::iterator it;
	it = channels.find(cmd[2]);
	if (it == channels.end()) {
		send_code(" " + cmd[2] + " :No such channel", cfd);
		return ;
	}
	for (size_t j = 0; j < channels[cmd[2]].chan_users.size(); j++) {
		if (channels[cmd[2]].chan_users[j]->nick == cmd[1]) {
			send_code(cmd[1] + " " + cmd[2] + " :is already on channel", cfd);
			return ;
		}
	}
	if (user_inchan(cmd[2], cfd) == -1) {
		send_code(" " + cmd[2] + " :User not on channel", cfd);
		return ;
	}
	if (!oper_inchan(cmd[2], cfd) && channels[cmd[2]].mode_inv) {
		send_code(" " + cmd[2] + " :You're not channel operator", cfd);
		return ;
	}
	for (size_t j = 0; j < clients.size(); j++) {
		if (users[clients[j].fd].nick == cmd[1]) {
			send_code(" " + cmd[1] + " " + cmd[2], cfd);
			std::string msg = ":" + users[cfd].nick + "!" + users[cfd].user + "INVITE " + cmd[1] + " " + cmd[2] + "\r\n";
			if (send(clients[j].fd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << clients[j].fd << SEND_ERROR << RESET;
			channels[cmd[2]].chan_invitees.push_back(users[clients[j].fd].nick);
			break ;
		}
	}
}

void
Command::mode(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 3 || cmd.size() > 4)
		return ;
	if (cmd[1][0] != '#' || (cmd[2][0] != '+' && cmd[2][0] != '-') || cmd[2].size() != 2)
		return ;
	std::map<std::string, t_chan>::iterator it;
	it = channels.find(cmd[1]);
	if (it == channels.end()) {
		send_code(" " + cmd[1] + " :No such channel", cfd);
		return ;
	}
	if (user_inchan(cmd[1], cfd) == -1) {
		send_code(" " + cmd[1] + " :User not on channel", cfd);
		return ;
	}
	if (!oper_inchan(cmd[1], cfd)) {
		send_code(" " + cmd[1] + " :You're not channel operator", cfd);
		return ;
	}
	if (cmd[2] == "+o") {
		if (cmd.size() != 4)
			return ;
		for (size_t j = 0; j < channels[cmd[1]].chan_users.size(); j++) {
			if (channels[cmd[1]].chan_users[j]->nick == cmd[3]) {
				if (oper_inchan(cmd[1], channels[cmd[1]].chan_users[j]->cfd))
					return ;
				channels[cmd[1]].chan_operators.push_back(channels[cmd[1]].chan_users[j]->cfd);
				break ;
			}
		}
	}
	else if (cmd[2] == "+i" && !channels[cmd[1]].mode_inv && cmd.size() == 3)
		channels[cmd[1]].mode_inv = true;
	else if (cmd[2] == "-i" && channels[cmd[1]].mode_inv && cmd.size() == 3)
		channels[cmd[1]].mode_inv = false;
	else if (cmd[2] == "-l" && cmd.size() == 3)
		channels[cmd[1]].mode_limit = -1;
	else if (cmd[2] == "+l") {
		if (cmd.size() != 4)
			return ;
		std::istringstream iss(cmd[3]);
		int	a = -1;
		iss >> a;
		if (a < 1)
			return ;
		channels[cmd[1]].mode_limit = a;
	}
	else if (cmd[2] == "-k" && cmd.size() == 3)
		channels[cmd[1]].chan_key = "";
	else if (cmd[2] == "+k") {
		if (cmd.size() != 4)
			return ;
		std::istringstream iss(cmd[3]);
		iss >> channels[cmd[1]].chan_key;
	}
	else if (cmd[2] == "+t" && cmd.size() == 3)
		channels[cmd[1]].mode_topic = true;
	else if (cmd[2] == "-t" && cmd.size() == 3)
		channels[cmd[1]].mode_topic = false;
	else
		return ;
	std::string msg = ":" + users[cfd].nick + "!" + users[cfd].user + "MODE ";
	msg += cmd[1] + " " + cmd[2];
	if (cmd.size() == 4)
		msg += " " + cmd[3];
	msg += "\r\n";
	for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++) {
		if (send(channels[cmd[1]].chan_users[i]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
			std::cerr << RED "Client " << channels[cmd[1]].chan_users[i]->cfd << SEND_ERROR << RESET;
	}
}

void
Command::join(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() > 3)
		return ;
	if (cmd.size() < 2) {
		send_code(" JOIN", cfd);
		return ;
	}
	std::istringstream	iss(cmd[1]);
	std::vector<std::string>	chan;
	std::vector<std::string>	key;
	std::string	tmp;
	while (getline(iss, tmp, ','))
		chan.push_back(tmp);
	tmp = "";
	if (cmd.size() > 2) {
		std::istringstream	ikk(cmd[2]);
		while (getline(ikk, tmp, ','))
			key.push_back(tmp);
	}
	std::map<std::string, t_chan>::iterator it;
	for (size_t i = 0; i < chan.size(); i++) {
		it = channels.find(chan[i]);
		if (it != channels.end()) {
			if ((i < key.size() && channels[chan[i]].chan_key != key[i]) || (i >= key.size() && !channels[chan[i]].chan_key.empty())) {
				send_code(" " + chan[i] + " (+k)", cfd);
				continue ;
			}
			if (channels[chan[i]].mode_limit > 0 && channels[chan[i]].mode_limit <= channels[chan[i]].chan_users.size()) {
				send_code(" " + chan[i] + " (+l)", cfd);
				continue ;
			}
			if (channels[chan[i]].mode_inv && !user_invited(chan[i], cfd)) {
				send_code(" " + chan[i] + " (+i)", cfd);
				continue ;
			}
		}
		else {
			t_chan	new_chan;
			if (i < key.size())
				new_chan.chan_key = key[i];
			new_chan.mode_inv = false;
			new_chan.mode_topic = false;
			new_chan.mode_limit = -1;
			new_chan.chan_operators.push_back(cfd);
			channels[chan[i]] = new_chan;
		}
		channels[chan[i]].chan_users.push_back(&(users[cfd]));
		std::string msg;
		for (size_t j = 0; j < channels[chan[i]].chan_users.size(); j++) {
			if (send(channels[chan[i]].chan_users[j]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << channels[chan[i]].chan_users[j]->cfd << SEND_ERROR << RESET;
		}
		std::vector<std::string> top;
		top.push_back("/topic");
		top.push_back(chan[i]);
		topic(top, cfd);
		msg = chan[i] + " members : ";
		// msg = users[cfd].nick + " = " + chan[i] + " ";
		for (size_t j = 0; j < channels[chan[i]].chan_users.size(); j++)
			msg += channels[chan[i]].chan_users[j]->nick + " ";
		msg += "\r\n";
		for (size_t j = 0; j < channels[chan[i]].chan_users.size(); j++) {
			if (send(channels[chan[i]].chan_users[j]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
				std::cerr << RED "Client " << channels[chan[i]].chan_users[j]->cfd << SEND_ERROR << RESET;
			send_code(chan[i], channels[chan[i]].chan_users[j]->cfd);
		}
		std::vector<std::string>::iterator sit = find(channels[chan[i]].chan_invitees.begin(), channels[chan[i]].chan_invitees.end(), users[cfd].nick);
		if (sit != channels[chan[i]].chan_invitees.end())
			channels[chan[i]].chan_invitees.erase(sit);

	}
}

void
Command::part(std::vector<std::string> cmd, int cfd) {
	if (cmd.size() < 2) {
		send_code(EMPTY, cfd);
		return ;
	}
	std::map<std::string, t_chan>::iterator it;
	std::string	msg;

	it = channels.find(cmd[1]);
	if (it != channels.end()) {
		if (user_inchan(cmd[1], cfd) != -1) {
			msg = ":" + users[cfd].nick + "!" + users[cfd].user;
			msg += "PART " + cmd[1] + "\r\n";
			for (size_t i = 0; i < channels[cmd[1]].chan_users.size(); i++) {
				if (send(channels[cmd[1]].chan_users[i]->cfd, msg.c_str(), msg.length(), 0) == ERROR)
					std::cerr << RED "Client " << channels[cmd[1]].chan_users[i]->cfd << SEND_ERROR << RESET;
			}
			std::vector<int>::iterator vit = find(channels[cmd[1]].chan_operators.begin(), channels[cmd[1]].chan_operators.end(), cfd);
			if (vit != channels[cmd[1]].chan_operators.end())
				channels[cmd[1]].chan_operators.erase(vit);
			channels[cmd[1]].chan_users.erase(channels[cmd[1]].chan_users.begin() + user_inchan(cmd[1], cfd));
			if (channels[cmd[1]].chan_users.empty())
				channels.erase(cmd[1]);
		}
		else
			send_code(cmd[1] + " :User not on channel", cfd);
	}
	else
		send_code(cmd[1] + " :No such channel", cfd);
}
