#include "command/Command.hpp"

Pass::Pass(Server* srv, bool auth) : Command(srv, auth) {}

Pass::~Pass() {}

// syntax: PASS <password>

void	Pass::execute(Client* client, std::vector<std::string> args) {
	if (args.empty()) {
		client->reply(ERR_NEEDMOREPARAMS(client->get_nickname(), "PASS"));
		return;
	}

	if (client->is_registered()) {
		client->reply(ERR_ALREADYREGISTERED(client->get_nickname()));
		return;
	}

	if (_srv->get_password() != args[0].substr(args[0][0] == ':' ? 1 : 0)) {
		client->reply(ERR_PASSWDMISMATCH(client->get_nickname()));
		return;
	}

	client->set_state(LOGIN);
}
