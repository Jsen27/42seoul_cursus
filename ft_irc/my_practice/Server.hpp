#pragma once

#include <iostream>

class Server{
private:
	std::string host;
	std::string port;
	std::string pw;
public:
	Server(const std::string& host, const std::string& pw);

	void on();
};
