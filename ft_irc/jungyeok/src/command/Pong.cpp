#include "command/Command.hpp"

Pong::Pong(Server* srv) : Command(srv) {}

Pong::~Pong() {}

// syntax: PONG <server1> [<server2>]

void	Pong::execute(Client* client, std::vector<std::string> args) {
	if (args.empty()) {
		client->reply(ERR_NEEDMOREPARAMS(client->get_nickname(), "PONG"));
		return;
	}

	client->write(RPL_PING(client->get_prefix(), args.at(0)));
}
