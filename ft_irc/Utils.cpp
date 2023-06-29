#include "Server.hpp"

void	ft_update_list(Server serv, std::string channel, int j, std::list<User> userlist)
{
	std::cout << "Channel found, user added!" << std::endl;
	std::string msg = ":" + serv.getList()[j].getNickname() + "! JOIN " + channel + "\r\n";
	std::list<User>::iterator ite = userlist.begin();
	std::string users;
	while (ite != userlist.end())
	{
		users += (*ite).getNickname();
		users += " ";
		ite++;
	}
	ite = userlist.begin();
	std::string server = "IRCserv";
	Channel& ch = serv.getChanFromName(channel);
	while (ite != userlist.end())
	{
		serv.sendData((*ite).getSocket(), msg);
		ite++;
	}
	for (std::list<User>::iterator sbirr = ch.getManager().begin(); sbirr != ch.getManager().end(); sbirr++)
	{
		std::string msg3 = ":IRCserv MODE "  + channel + " +o " + (*sbirr).getNickname() + "\r\n";
		serv.ft_send_all_chan(serv, ch, msg3);
	}
}


void	ft_part_list(Server serv, std::string channel, int j, std::list<User> userlist)
{
	std::cout << "Channel found, user added!" << std::endl;
	std::string msg = ":PART " + channel + "\r\n";
	std::list<User>::iterator ite = userlist.begin();
	std::string users;
	while (ite != userlist.end())
	{
		users += (*ite).getNickname();
		users += " ";
		ite++;
	}
	ite = userlist.begin();
	std::string server = "IRCserv";
	Channel& ch = serv.getChanFromName(channel);
	while (ite != userlist.end())
	{
		
		std::string msg1 = ":" + server + " 353 " + (*ite).getNickname() + " = " + channel + " :" + users + "\r\n";
		std::string msg2 = ":" + server + " 366 " + (*ite).getNickname() + " " + channel + " :End of /NAMES list\r\n";
		serv.sendData((*ite).getSocket(), msg);
		serv.sendData((*ite).getSocket(), msg1);
		serv.sendData((*ite).getSocket(), msg2);
		ite++;
	}
	for (std::list<User>::iterator sbirr = ch.getManager().begin(); sbirr != ch.getManager().end(); sbirr++)
	{
		std::string msg3 = ":IRCserv MODE "  + channel + " +o " + (*sbirr).getNickname() + "\r\n";
		serv.ft_send_all_chan(serv, ch, msg3);
	}
}

void	ft_kick_list(Server serv, std::string channel, int j,std::list<User> *userlist, std::string nick)
{
	std::cout << "Channel found, user removed!" << std::endl;
	std::string msg = ":" + serv.getList()[j].getNickname() + " KICK " + channel + " " + nick + "\r\n";
	std::list<User>::iterator it = userlist->begin();
	std::string users;
	while (it != userlist->end())
	{
		users += (*it).getNickname();
		users += " ";
		it++;
	}
	it = userlist->begin();
	std::string server = "IRCserv";
	while (it != userlist->end())
	{
		serv.sendData((*it).getSocket(), msg);
		it++;
	}
	it = userlist->begin();
	while (it != userlist->end())
	{
		if ((*it).getNickname() == nick)
			userlist->erase(it);
		std::cout << "User removed from channel!" << std::endl;
		break;
		it++;
	}
}

void	ft_send_all(Server serv, std::string channel, int j, std::list<User> userlist, std::string msg)
{
	std::list<User>::iterator it = userlist.begin();
	while (it != userlist.end())
	{
		serv.sendData((*it).getSocket(), msg);
		it++;
	}
}

int	init(int ac, char **av, Server &serv)
{
	if (ac != 3)
	{
		std::cout << "usage ./ircserv <port> <password>" << std::endl;
		return(1);
	}
	try
	{
		std::stoi(av[1]);
		if (std::stoi(av[1]) < 1024 || std::stoi(av[1]) > 65535)
		{
			std::cerr << "Insert a numeric value between 1024 ~ 65535" << std::endl;
			return(1);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Insert a numeric value" << std::endl;
	}
	serv.generateBestemmieFromFile();
	serv.setPort(std::stoi(av[1]));
	serv.setPassword(av[2]);
    if (serv.createSocket() == -1)
	{
		std::cout << "Socket not create!" << std::endl;
		return (1);
	}
	std::cout << "Socket create!" << std::endl;
	if (listen(serv.getServerSock(), 10) == -1)
	{
		std::cout << "Listen not create!" << std::endl;
		return (1);
	}
	std::cout << "Listen create!" << std::endl;
	return (0);
}

void	ft_send_channel(Server serv, std::string channel, int j)
{
	std::string server_name = "IRCserv";
	Channel ch = serv.getChanFromName(channel);
	if (ch.getEmpty() == true)
	{
		std::string msg = ":" + server_name + " 403 " + serv.getList()[j].getNickname() + " " + channel + " :No such channel\r\n";
		serv.sendData(serv.getList()[j].getSocket(), msg);
		return ;
	}
	std::string topic = ch.getTopic();


	//send JOIN msg
	std::string msg = ":" + serv.getList()[j].getNickname() + " JOIN " + channel + "\r\n";
	serv.sendData(j, msg);

	//send RPL_TOPIC
	msg = ":" + server_name + " 332 " + serv.getList()[j].getNickname() + " " + channel + " :" + topic + "\r\n";
	serv.sendData(j, msg);

	//send RPL_NAMREPLY
	std::list<User>::iterator ite = ch.getListUsers().begin();
	std::string users;
	while (ite != ch.getListUsers().end())
	{
		users += (*ite).getNickname();
		users += " ";
		ite++;
	}
	msg = ":" + server_name + " 353 " + serv.getList()[j].getNickname() + " = " + channel + " :" + users + "\r\n";
	serv.sendData(j, msg);

	//send RPL_ENDOFNAMES
	msg = ":" + server_name + " 366 " + serv.getList()[j].getNickname() + " " + channel + " :End of /NAMES list\r\n";
	serv.sendData(j, msg);
}