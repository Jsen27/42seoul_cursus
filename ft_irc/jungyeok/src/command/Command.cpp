#include "command/Command.hpp"

Command::Command(Server* srv, bool auth) :_srv(srv), _auth(auth) {}

Command::~Command() {}

bool	Command::auth_required() const {
	return _auth;
}
