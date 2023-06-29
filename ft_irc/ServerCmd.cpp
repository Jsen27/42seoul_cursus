#include "Server.hpp"

int Server::pass(std::string nick, int j, int mes)
{
    if (mes != 2)
        return (1);
    std::istringstream ss(nick);
    std::string password;
    ss >> password;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Server Password: " << getPassword() << std::endl;
    if (password == ":" + getPassword())
    {
        std::cout << "Correct password, congratulations!" << std::endl;
        std::string msg = getServerName() + " Correct password, congratulations!\r\n";
        send(j, msg.c_str(), msg.length(), 0);
    }
    else
    {
        std::cout << "Incorrect password, closing connection!" << std::endl;
        std::string msg = "464 :IRCserv Incorrect password, closing connection! \r\n";
        sendData(j, msg);
        close(j);
        getList().erase(j);
    }
    return 1;
}

int Server::ping(std::string nick, int j)
{
	std::string pong = "PONG " + getList()[j].getNickname() + "\r\n";
	sendData(j, pong);
	return 1;
}

int	Server::who(std::string nick, int j)
{
	std::istringstream ss(nick);
	std::string list;
	std::string str;
	ss >> str;
	std::cout << "WHO: " << str << std::endl;
	for(std::list<Channel>::iterator itChannel = getChannels().begin(); itChannel != getChannels().end(); ++itChannel)
	{
		if (itChannel->getName() == str)
		{
			list = ":" + getServerName() + "! 353 " + getList()[j].getNickname() + " = " + itChannel->getName() + " :";
			for (std::list<User>::iterator itClient = itChannel->getListUsers().begin(); itClient != itChannel->getListUsers().end(); ++itClient)
			{
		// :hostname 353 nickname = #channel :nickname nickname (can be more than one here or sent in multiple messages)
				list += itClient->getNickname() + " ";
			}
			list += "\r\n:" + getServerName() + "! 366 " + getList()[j].getNickname() + " " + itChannel->getName() + " :End of /NAMES list.\r\n";
			std::cout << "LIST: " << list << std::endl;
			sendData(j, list);
		}
	}
	// std::map<int, User>::iterator itUser = getList().begin();
	for(std::map<int, User>::iterator itUser = getList().begin(); itUser != getList().end(); ++itUser)
	{
		if (itUser->second.getNickname() == str)
		{
			list = ":" + getServerName() + "! 352 " + getList()[j].getNickname() + " =";
			for (std::list<Channel>::iterator itChannel = getChannels().begin(); itChannel != getChannels().end(); ++itChannel)
			{
				if (itChannel->isUserIn(str))
				{
					list += " " + itChannel->getName();
				}
			// :hostname 353 nickname = #channel :nickname nickname (can be more than one here or sent in multiple messages)
			}
			list += " " + itUser->second.getUsername() + " " /*+ itUser->second.getHostname() + " "*/ + getServerName() + " " + itUser->second.getNickname() + " H :0 " + itUser->second.getUsername() + "\r\n";
			std::cout << "LIST: " << list << std::endl;
			sendData(j, list);
		}
	}
	return (1);
}

int Server::privmsg(std::string command, int j)
{
    std::istringstream ss(command);
    std::string nick;
    ss >> nick;
    std::string sender_nick = getList()[j].getNickname();
    std::cout << "Sender: " << sender_nick << std::endl;
    if (nick[0] == '#')
    {
        std::string msg;
        std::cout << "Nick: " << nick << std::endl;
        Channel& chan = getChanFromName(nick);
        std::list<User>::iterator it = chan.getListUsers().begin();
        if (chan.getEmpty() == true)
        {
            std::string msg = ":IRCserv 403 " + getList()[j].getNickname() + " " + nick + " :No such channel\r\n";
            sendData(getList()[j].getSocket(), msg);
            return (1);
        }
        for (; it != chan.getListUsers().end(); it++)
        {
            if ((*it).getNickname() == sender_nick)
                break;
        }
        if (it == chan.getListUsers().end())
        {
            std::cout << "User not belonging to the channel!" << std::endl;
            sendData(j, "IRCserv User not belonging to the channel!\r\n");
            return (1);
        }
        std::list<User>::iterator ite = chan.getListUsers().begin();
        while (command.find(":"))
            ss >> command;
        command.erase(0, 1);
        msg = ":" + sender_nick + " PRIVMSG " + nick + " :";
        while (ss)
        {
            msg += command;
            msg += " ";
            ss >> command;
        }
        msg.erase(msg.length() - 1, 1);
        msg += "\r\n";
        std::cout << "Message: " << msg << std::endl;
        while (ite != chan.getListUsers().end())
        {
            if ((*ite).getNickname() != sender_nick)
                sendData((*ite).getSocket(), msg);
            ite++;
        }
    }
    else
    {
        std::string msg;
        std::cout << "Nick: " << nick << std::endl;
        std::cout << "command: " << command << std::endl;
        if (isUserReal(nick))
        {
            int r_sock = getUserSockFromNick(nick);
            while (command.find(":"))
                ss >> command;
            command.erase(0, 1);
            msg = ":" + sender_nick + "! PRIVMSG " + nick + " :";
            while (ss)
            {
                msg += command;
                msg += " ";
                ss >> command;
            }
            msg.erase(msg.length() - 1, 1);
            msg += "\r\n";

            std::cout << "Message: SURE: " << msg << std::endl;
            sendData(r_sock, msg);
        }
    }
    return (1);
}

int Server::join(std::string command, int j)
{
    std::istringstream ss(command);
    std::string channel;
    ss >> channel;
    std::cout << "Channel: " << channel << std::endl;
    std::list<Channel>::iterator it = getChannels().begin();
    for (; it != getChannels().end(); it++)
    {
        if ((*it).getName() == channel)
            break;
    }
    if (it == getChannels().end())
    {
        Channel new_channel(channel);
        new_channel.setListUsers(getList()[j]);
        new_channel.setManager(getList()[j]);
        getChannels().push_back(new_channel);
        std::cout << "Channel not found, created!" << std::endl;
        ft_send_channel(*this, channel, j);
        Channel& ch = getChanFromName(channel);
        std::string msg = ":IRCserv MODE " + channel + " +o " + getUserNameFromSock(j) + "\r\n";
        ft_send_all_chan(*this, ch, msg);
    }
    else
    {
        Channel& ch = getChanFromName(channel);

        if (ch.isInvOn() && !ch.isUserInvited(getUserNameFromSock(j)))
        {
            sendData(j, "You need to be invited to join this channel!\r\n");
            return (1);
        }
        else if (ch.isPwOn() != 0 && !ch.isUserInvited(getUserNameFromSock(j)))
        {
            if (ss)
            {
                std::string pw_ins;
                ss >> pw_ins;
                std::cout << "User-entered PW: " << std::endl;
                std::cout << "FIRST STEP" << std::endl;
                if (pw_ins != ch.getPw())
                {
                    std::cout << "SECOND STEP" << std::endl;
                    std::cout << "Channel PW: " << ch.getPw() << std::endl;
                    sendData(j, "You need to join with the correct channel password!\r\n");
                    return (1);
                }
            }
            else
            {
                std::cout << "THIRD STEP" << std::endl;
                sendData(j, "IRCserv You need to join with the channel password!\r\n");
                return (1);
            }
        }
        if (ch.isLimitOn() && ch.getLimit() == ch.getListUsers().size())
        {
            sendData(j, "Channel user limit reached!\r\n");
            return (1);
        }
        (*it).setListUsers(getList()[j]);
        ft_update_list(*this, channel, j, (*it).getListUsers());
        ft_send_channel(*this, channel, j);
        for (std::list<User>::iterator sbirr = ch.getManager().begin(); sbirr != ch.getManager().end(); sbirr++)
        {
            std::string msg3 = ":IRCserv MODE " + channel + " +o " + (*sbirr).getNickname() + "\r\n";
            sendData(j, msg3);
        }
        if (ch.isUserInvited(getUserNameFromSock(j)))
            ch.removeInvited(getUserNameFromSock(j));
    }
    return (1);
}

int Server::part(std::string command, int j)
{
    std::stringstream ss(command);
    std::string channel;
    ss >> channel;
    std::cout << "Channel: " << channel << std::endl;
    Channel& ch = getChanFromName(channel);
    std::list<User>::iterator it = ch.getListUsers().begin();
    if (!isChanReal(channel)) // channel not found
    {
        std::cout << "Channel not found!" << std::endl;
        sendData(j, "IRCserv Channel not found!\r\n");
        return (1);
    }
    if (ch.isUserIn(getUserNameFromSock(j)))
    {
        for (; it != ch.getListUsers().end(); it++)
        {
            if (it->getSocket() == j)
            {
                ch.getListUsers().erase(it);
                ch.removeManager(it->getNickname());
                std::cout << "User " << it->getNickname() << " removed from the channel!" << std::endl;
                break;
            }
        }
    }
    else
    {
        sendData(j, "IRCserv You cannot leave a channel you don't belong to!\r\n");
        return (1);
    }
    std::string msg = ":" + getList()[j].getNickname() + " PART " + channel + " \r\n";
    std::string msg1 = ":" + getList()[j].getNickname() + "!" + " PART :" + channel + "\n";
    ft_send_all_chan(*this, ch, msg1);
    sendData(j, msg);
    ft_check_channel(ch);
    return (1);
}

void	Server::partChannel(int j, Channel& channel)
{
		std::string msg1 = ":" + getList()[j].getNickname() +  "!" + " PART :" + channel.getName() + "\n";
		ft_send_all_chan(*this, channel, msg1);
}

int Server::kick(std::string command, int j)
{
    std::stringstream ss(command);
    std::string channel;
    ss >> channel; // save name of channel
    std::cout << "Channel: " << channel << std::endl;
    User sender_user = getList().find(j)->second; // get User from socket
    if (!isChanReal(channel)) // channel not found
    {
        std::cout << "Channel not found!" << std::endl;
        sendData(j, "IRCserv Channel not found!\r\n");
        return (1);
    }
    Channel& ch = getChanFromName(channel); // get Channel class
    std::list<User>::iterator it = ch.getListUsers().begin();
    std::string nick;
    ss >> nick; // get nick of kicked
    if (!ch.isUserManager(getUserNameFromSock(j)))
    {
        sendData(j, "IRCserv You are not a channel operator, you cannot kick people!\r\n");
        return (1);
    }
    else if (!ch.isUserIn(nick))
    {
        sendData(j, "IRCserv The user to be kicked is not part of the channel!\r\n");
        return (1);
    }
    else
    {
        for (; it != ch.getListUsers().end(); it++)
        {
            if (it->getNickname() == nick)
                break;
        }
    }
    std::string reason;
    std::string temp;
    while (ss)
    {
        ss >> temp;
        reason += temp;
        reason += " ";
        temp = "";
    }
    if (it != ch.getListUsers().end())
    {
        std::string msg = ":" + getList()[j].getNickname() + " KICK " + channel + " " + nick + " " + reason + "\r\n";
        std::string msg1 = ":" + getList()[j].getNickname() + "!" + " KICK " + channel + " " + nick + " " + reason + "\n";
        ft_send_all_chan(*this, ch, msg1);
        sendData(j, msg);
        if (ch.isUserManager(nick))
            ch.removeManager(nick);
        ch.getListUsers().erase(it);
        std::cout << "User " << it->getNickname() << " removed from the channel!" << std::endl;
    }
    ft_check_channel(ch);
    return (1);
}

int Server::topic(std::string command, int j)
{
    std::stringstream ss(command);
    std::string channel;
    ss >> channel;
    std::cout << "Channel: " << channel << std::endl;
    if (!isChanReal(channel))
    {
        std::cout << "Channel not found!" << std::endl;
        sendData(j, "IRCserv Channel not found!\r\n");
        return (1);
    }
    Channel ch = getChanFromName(channel);
    if (!ch.isUserManager(getUserNameFromSock(j)) && ch.istopicOn())
    {
        sendData(j, "IRCserv You are not a channel operator, you cannot change the topic!\r\n");
        return (1);
    }
    std::string tmp;
    std::string topic;
    ss >> topic;
    while (topic.find(":"))
        ss >> topic;
    command.erase(0, 1);
    while (ss >> tmp)
        topic += " " + tmp;
    std::cout << "Topic: " << topic << std::endl;
    std::string msg = ":" + getList()[j].getNickname() + " TOPIC " + channel + " " + topic + "\r\n";
    std::string msg1 = ":" + getList()[j].getNickname() + "!" + " TOPIC " + channel + " " + topic + "\n";
    ft_send_all(*this, channel, j, ch.getListUsers(), msg1);
    ch.setTopic(topic);
    return (1);
}

int Server::invite(std::string command, int j)
{
    std::stringstream ss(command);
    std::string pippo;
    std::string channel;
    ss >> pippo;
    ss >> channel;
    if (!isChanReal(channel))
    {
        std::cout << "Channel not found!" << std::endl;
        sendData(j, "IRCserv Channel not found!\r\n");
        return (1);
    }
    Channel& ch = getChanFromName(channel);
    if (!ch.isUserIn(getUserNameFromSock(j)))
    {
        sendData(j, "IRCserv You are not a member of the channel, you cannot invite others!\r\n");
        return (1);
    }
    if (!isUserReal(pippo))
    {
        sendData(j, "IRCserv The invited user does not exist!\r\n");
        return (1);
    }
    std::map<int, User>::iterator finder = getList().find(getUserSockFromNick(pippo));
    ch.setInvited(finder->second);
    std::string msg = ":" + pippo + " INVITE " + getList()[j].getNickname() + " " + channel + "\r\n";
    sendData(getUserSockFromNick(pippo), msg);
    return (1);
}

int Server::insulta(std::string command, int j)
{
	std::stringstream ss(command);
	std::string bastarduser;
	std::string channel;
	std::string temp;
	ss >> channel;
	while (ss)
	{
		ss >> temp;
		bastarduser += temp;
		bastarduser += " ";
		temp = "";
	}
	if (!isChanReal(channel))
	{
		std::cout << "Channel not found!" << std::endl;
		sendData(j, "IRCserv Channel not found!\r\n");
		return (1);
	}
	Channel& ch = getChanFromName(channel);
	if (command == "INSULTAMI" || command == "insultami")
		bastarduser = getUserNameFromSock(j);
	ft_send_all_chan(*this, ch, "Fuck " + bastarduser + " " + randomBestemmia() + "\r\n");
	return (1);
}

int Server::secret(std::string command, int j)
{
    std::stringstream ss(command);
    std::string secret;
    std::string channel;
    std::string temp;
    ss >> channel;
    while (ss)
    {
        ss >> temp;
        secret += temp;
        secret += " ";
        temp = "";
    }
    if (!isChanReal(channel))
    {
        std::cout << "Channel not found!" << std::endl;
        sendData(j, "IRCserv Channel not found!\r\n");
        return (1);
    }
    Channel& ch = getChanFromName(channel);
    ft_send_all_chan(*this, ch, "Secret " + secret + "\r\n");
    return (1);
}

int Server::channel(std::string command, int j)
{
	std::string msg = "IRCserv Available channels: ";
	bot_canali(*this, j);
	return (1);
}

int Server::mode(std::string command, int j)
{
	std::stringstream ss(command);
	std::string channel;
	ss >> channel;
	std::string mode;
	ss >> mode;
	std::string nick;
	ss >> nick;
	if(!isChanReal(channel))
	{
		std::cout << "Channel not found!" << std::endl;
		sendData(j, "IRCserv Channel not found!\r\n");
		return (1);
	}
	Channel& ch = getChanFromName(channel);
	std::list<User>::iterator it = ch.getListUsers().begin(); 
	if (mode == "+o" || mode == "-o")
	{
		if(!ch.isUserIn(getUserNameFromSock(j)) || !ch.isUserManager(getUserNameFromSock(j)))
		{
			sendData(j, "IRCserv You are not a channel manager!\r\n");
			return (1);
		}
		else if (!ch.isUserIn(nick))
		{
			sendData(j, "IRCserv responding user is not part of the channel!\r\n");
			return (1);
		}
		else if (mode == "+o")
		{
			if(ch.isUserManager(nick))
			{
				sendData(j, "IRCserv users are already channel managers!\r\n");
				return (1);
			}
			else
			{
				std::map<int, User>::iterator finder = getList().find(getUserSockFromNick(nick));
				ch.setManager(finder->second);
				std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " +o " + nick + "\r\n";
				ft_send_all_chan(*this, ch, msg);
				std::cout << "The user " << nick << "now he is a channel manager!" << std::endl;
			}
		}
		else
		{
			if(ch.isUserManager(nick))
			{
				std::list<User>::iterator finder = ch.getManager().begin();
				for (; finder != ch.getManager().end(); finder++)
				{
					if (finder->getNickname() == nick)
					{
						ch.removeManager(nick);
						std::cout << "The user " << nick << " now not a channel manager" << std::endl;
						std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " -o " + nick + "\r\n";
						ft_send_all_chan(*this, ch, msg);
						break ;
					}
				}
			}
			else
			{
				sendData(j, "IRCserv users are already normal users of the channel!\r\n");
				return (1);
			}
		}
	}
	if (ch.isUserManager(getUserNameFromSock(j)))
	{
		if (mode == "+k")
		{
			ch.setPw(nick);
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " +k " + nick + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "-k")
		{
			ch.removePw();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " -k " + nick + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "+i")
		{
			ch.setInvOn();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " +i " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "-i")
		{
			ch.removeInvOn();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " -i " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "+t")
		{
			ch.setopicOn();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " +t " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "-t")
		{
			ch.removetopicOn();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " -t " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "-l")
		{
			ch.removeLimitOn();
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " -l " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
		else if (mode == "+l")
		{
			int limit = 500;
			if (nick != " ")
			{
				try
				{
					std::stoi(nick);
				}
				catch(const std::exception& e)
				{
					std::string msg = "IRCserv The entered parameter is not a number!\r\n";
					sendData(j, msg);
					return (1);
				}		
			}
			limit = std::stoi(nick);
			if (limit < 1)
			{
				std::string msg = "IRCserv The entered parameter is invalid!\r\n";
				sendData(j, msg);
				return (1);
			}
			std::cout << "limit: " << limit << std::endl;
			ch.setLimitOn(*this, limit);
			std::string msg = ":"+ getList()[j].getNickname() + " MODE "  + channel + " +l " + std::to_string(limit) + " " + "\r\n";
			ft_send_all_chan(*this, ch, msg);
		}
	}
	else
		ft_no_manager_catch(j, ch, mode);
	return (1);
}

int Server::quit(std::string command, int j)
{
	ft_delete_user(j);
	close(j);
	getList().erase(j);
	return(1) ;
}

int Server::nick(std::string command, int j, int mes)
{
    if (mes != 3)
        return (1);
	std::stringstream ss(command);
	std::string nick;
	ss >> nick;
	std::cout << "Nick : " << nick << std::endl;
	getList()[j].setNickname(nick);
	std::cout << "Nick save : " << getList()[j].getNickname() << std::endl;
    return (1);
}

int Server::user(std::string command, int j, int mes)
{
	if (mes != 4)
		return (1);
	std::stringstream ss(command);
	std::string user;
	while (command.find(":"))
		ss >> command;
	command.erase(0, 1);
	while(ss)
	{
		user += command;
		user += " ";
		ss >> command;
	}
	user.erase(user.length() - 1, 1);
	std::cout << "User : " << user << std::endl;
	getList()[j].setUsername(user);
	std::cout << "User save : " << getList()[j].getUsername() << std::endl;
	std::string welcome = "001 "+ getList()[j].getNickname() + " :Welcome to the IRCserver, " + getList()[j].getNickname() + "\r\n";
	sendData(j, welcome);
	welcome = "IRCserv This is NOT the global chat, to join a channel type /join <channel_name>!\r\n";
	sendData(j, welcome);
	return (1);
}
