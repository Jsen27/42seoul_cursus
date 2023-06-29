#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <list>
#include <poll.h>
#include <fcntl.h>
#include <sstream>
#include "Server.hpp"
#include "User.hpp"

class Server;

class Channel
{
	private:
		std::string		_name;
		std::list<User> 	_users;
		std::list<User> 	_manager;
		std::list<User> 	_invited;
        std::string _topic;
		std::string _pw;
		int _pwOn;
		int _invOn;
		int _topicOn;
        int _empty;
		int _limitOn;
		int _limit;
		int _stop;

	public:
		Channel();
		Channel(std::string &name);
		~Channel();
		std::string& getName();
		std::list<User>& getListUsers();
		std::list<User>& getManager();
		std::list<User>& getInvited();
        std::string& getTopic();
		std::string &getUserNick(int socket);
		User &getUser(int socket);
		std::string getPw();
		int	isPwOn();
		int	isInvOn();
		void setInvOn();
		int	istopicOn();
		int	isLimitOn();
		int	getLimit();
		void setLimitOn(Server & serv, int limit);
		void setopicOn();
		void setPw(std::string &pw);
        void setTopic(std::string& topic);
		void setManager(User &manager);
		void setInvited(User &invited);
		void setName(std::string &name);
		void setListUsers(User &user);
        void setEmpty(int empty);
        int getEmpty();
		void initMode();
		void removePw();
		void removeInvOn();
		void removetopicOn();
		void removeLimitOn();
		int	isUserIn(std::string user);
		int	isUserManager(std::string user);
		int	isUserInvited(std::string user);
		void remove_User(Channel ch, std::string user);
		void removeManager(std::string manager);
		void removeInvited(std::string invited);
		int checkFull();
};

#endif