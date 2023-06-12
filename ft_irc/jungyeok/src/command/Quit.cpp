#include "command/Command.hpp"

Quit::Quit(Server* srv, bool auth) : Command(srv, auth) {}

Quit::~Quit() {}

// syntax: QUIT [<message>]

void	Quit::execute(Client* client, std::vector<std::string> args) {
	std::string reason = args.empty() ? "Leaving..." : args.at(0);

	if (reason.at(0) == ':')
		reason = reason.substr(1);

	client->write(RPL_QUIT(client->get_prefix(), reason));
	_srv->on_client_disconnect(client->get_fd());
}
