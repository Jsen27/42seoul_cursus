#include "command/Command.hpp"

Notice::Notice(Server* srv) : Command(srv) {}

Notice::~Notice() {}

// syntax: NOTICE <msgtarget> <message>

void	Notice::execute(Client* client, std::vector<std::string> args) {
	if (args.size() < 2 || args[0].empty() || args[1].empty()) {
		client->reply(ERR_NEEDMOREPARAMS(client->get_nickname(), "NOTICE"));
		return;
	}

	// extract the target and the message

	std::string target = args.at(0);
	std::string message;

	std::vector<std::string>::iterator it = args.begin() + 1;
	std::vector<std::string>::iterator end = args.end();

	while (it != end) {
		message.append(*it + " ");
		it++;
	}

	if (message.at(0) == ':')
		message = message.substr(1);

	// if notice is for a channel

	if (target.at(0) == '#') {
		Channel* channel = client->get_channel();

		// channel not found
		if (!channel) {
			client->reply(ERR_NOSUCHCHANNEL(client->get_nickname(), target));
			return;
		}

		// channel is not for external messages
		if (!channel->ext_msg()) {
			std::vector<std::string> nicknames = channel->get_nicknames();

			std::vector<std::string>::iterator it = nicknames.begin();
			std::vector<std::string>::iterator end = nicknames.end();

			// check if client is in the channel
			while (it != end) {
				if (*it == client->get_nickname())
					break;

				it++;
			}

			// if not in channel
			if (it == end) {
				client->reply(ERR_CANNOTSENDTOCHAN(client->get_nickname(), target));
				return;
			}
		}

		channel->broadcast(RPL_NOTICE(client->get_prefix(), target, message), client);
		return;
	}

	// else if notice is for a client

	Client  *dest = _srv->get_client(target);
	if (!dest) {
		client->reply(ERR_NOSUCHNICK(client->get_nickname(), target));
		return;
	}

	dest->write(RPL_NOTICE(client->get_prefix(), target, message));
}
