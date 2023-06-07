#include <IrcServer.hpp>


/*
** Регистрирует соединение клиента с сервером
**
** @Command: PASS
** @Parameters: <password>
**
*/

void	IrcServer::PASS(std::vector<std::string> arguments, int fd)
{
    ClientIrc *client;

    _MainServer->Logger(PURPLE, "Make command PASS");


    client = _MainServer->GetClientFromFd(fd);

    /* Если уже подключен */
    if (client->is_connected())
    {
        this->SendInFd(fd, ERR_ALREADYREGISTRED(client->getNickName()));
    }
    else if (arguments.size() > 1)
    {
       
        if (arguments[1] == _pass)
        {
            _MainServer->Logger(GREEN, "Successfully password!");
            ChangeClientStatus(fd);                   
        }
        else
        {
            this->SendInFd(fd, ERR_PASSWDMISMATCH(client->getNickName()));
        }
    }
    else
    {
        this->SendInFd(fd, ERR_NEEDMOREPARAMS(client->getNickName(), std::string("PASS")));
    }

}


/*
** Устанавливает юзернейм и реальное имя пользователя для регистрации
**
** @Command: USER
** @Parameters: <username> <host> <server> :<realname>
*/

void	IrcServer::USER(std::vector<std::string> arguments, int fd)
{
    ClientIrc *client;

    _MainServer->Logger(PURPLE, "Make command USER");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_connected())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() == 5)
    {
        //USER Adium * 127.0.0.1 :Пользователь Adium
        // std::cout << "1 " << arguments[0] << std::endl;  // USER
        // std::cout << "2 " << arguments[1] << std::endl;  // Adium
        // std::cout << "3 " << arguments[2] << std::endl;  // *
        // std::cout << "4 " << arguments[3] << std::endl;  // 127.0.0.1
        // std::cout << "5 " << arguments[4] << std::endl;  // Пользователь Adium

        /* Check name */
        for (std::vector<ClientIrc*>:: iterator start = _MainServer->_Clients.begin(); start != _MainServer->_Clients.end(); start++)
        {
            if ((*start)->getName() == arguments[1])
            {
                if (client->getNickName() == "")
                {
                    this->SendInFd(fd, ERR_ALREADYREGISTRED(std::string("*")));
                }
                else
                {
                    this->SendInFd(fd, ERR_ALREADYREGISTRED(client->getNickName()));
                }
                return;
            }
        }
        client->setName(arguments[1]);
        client->SetRealName(arguments[4]);
        // if (!client->is_authenticated())
        // {
        //     client->ChangeStatusAuthenticated();
        //     WelcomeUser(client, fd);
        // }
    }
    else
    {
        this->SendInFd(fd, ERR_NEEDMOREPARAMS(client->getNickName(), std::string("USER")));
    }

}

void    IrcServer::WelcomeUser(ClientIrc *client, int fd)
{
    std::string nickname = client->getNickName();

    this->SendInFd(fd, RPL_MOTDSTART(nickname));
    this->SendInFd(fd, RPL_MOTD(nickname, "hi"));
    this->SendInFd(fd, RPL_ENDOFMOTD(nickname));
    this->SendInFd(fd, RPL_WELCOME(nickname));
    this->SendInFd(fd, RPL_YOUREOPER(nickname));         

}


bool    isValidNickname(const std::string& nick)
{
    const std::string spec = "-[]^{}";
    if (nick.length() > 9)
        return false;
    for (unsigned long i = 0; i < nick.length(); ++i)
    {
        if (!std::isalnum(nick[i]) && spec.find(nick[i]) == std::string::npos)
            return false;
    }
    return true;
}


/*
** Устанавливает новый ник или изменяет старый
**
** @Command: NICK
** @Parameters: <nickname>
**
*/

void	IrcServer::NICK(std::vector<std::string> arguments, int fd)
{
    ClientIrc *client;

    _MainServer->Logger(PURPLE, "Make command NICK");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_connected())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }

    else if (arguments.size() < 2)
    {
        this->SendInFd(fd, ERR_NONICKNAMEGIVEN(client->getNickName()));

    }
    else if (FindClientrByNickname(arguments[1]) != NULL)
    {
        this->SendInFd(fd, ERR_NICKNAMEINUSE(client->getNickName(), arguments[1]));   
    }
    else if (!isValidNickname(arguments[1]))
    {
        this->SendInFd(fd, ERR_ERRONEUSNICKNAME(std::string("*"), arguments[1]));
        //this->QUIT(arguments, fd);
    }
    else
    {
        
        if (!client->is_authenticated())
        {
            
            client->ChangeStatusAuthenticated();
            client->SetNickName(arguments[1]);
            WelcomeUser(client, fd);
        }
        else
        {   this->SendInFd(fd, RPL_ENDOFMOTD(arguments[1]));
            client->SetNickName(arguments[1]);
        }
    }
}

/*
** Сессия пользователя заканчивается с QUIT-сообщением.
**
** @Command: QUIT
** @Parameters: <message>
**
*/


void	IrcServer::QUIT(std::vector<std::string> arguments, int fd)
{
    ClientIrc *client;

    _MainServer->Logger(PURPLE, "Make command QUIT");

    client = _MainServer->GetClientFromFd(fd);
    this->SendInFd(fd, RPL_QUIT(client->getNickName(), arguments.size() > 1 ? arguments[1] : "silently"));
    _MainServer->RemoveClient(fd);
}


/*
** Проверка активности клиента/сервера на другой стороне соединения.
**
** @Command: PING
** @Parameters: <server>
**
*/

void	IrcServer::PING(std::vector<std::string> arguments, int fd)
{
    ClientIrc *client;

    _MainServer->Logger(PURPLE, "Make command PING");

    client = _MainServer->GetClientFromFd(fd);

    if (arguments.size() < 2)
    {
        this->SendInFd(fd, ERR_NOORIGIN(client->getNickName()));
    }
    else
    {
        this->SendInFd(fd, std::string("PONG ") + arguments[1] + std::string(" ") + client->getNickName());
    }

}


/*
** Устанавливает автоматический ответ на сообщение PRIVMSG
** Если вызывается без аргументов, отменяет его
**
** @Command: AWAY
** @Parameters: <message>
**
*/

void	IrcServer::AWAY(std::vector<std::string> arguments, int fd)
{

    ClientIrc   *client;

    _MainServer->Logger(PURPLE, "Make command AWAY");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() == 1 && client->is_away())
    {
        this->SendInFd(fd, RPL_UNAWAY(client->getNickName()));
        client->SetAwayMsg("");
    }
    else if (arguments.size() > 1)
    {
        this->SendInFd(fd, RPL_NOWAWAY(client->getNickName()));
        std::string big_away;

        big_away = "";
        for (unsigned long i = 1; i < arguments.size(); i++)
        {
            big_away += arguments[i];
            big_away += " ";
        }

        client->SetAwayMsg(big_away);
    }
}



/*
** Отправляет личное сообщение, учитывая автоматический ответ
**
** @Command: PRIVMSG
** @Parameters: <nickname> :<message>
**
*/

void	IrcServer::PRIVMSG(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;
    ClientIrc   *client_to_send;

    _MainServer->Logger(PURPLE, "Make command PRIVMSG");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() != 3)
    {
        if (arguments.size() == 2)
        {
            if (arguments[1].find(':') != std::string::npos)
            {
                this->SendInFd(fd, ERR_NORECIPIENT(client->getNickName(), arguments[0]));
            }
            else
            {
                this->SendInFd(fd, ERR_NOTEXTTOSEND(client->getNickName()));
            }
        }
        else
        {
            this->SendInFd(fd, ERR_TOOMANYTARGETS(client->getNickName(), arguments[1]));
        }

    }
    else if (FindClientrByNickname(arguments[1]) == NULL)
    {
        //this->SendInFd(fd, ERR_NOSUCHNICK(client->getNickName(), arguments[1]));

        Channel *channel;
        channel = FindChannelByName(arguments[1]);
        
        if (channel == NULL)
        {
            this->SendInFd(fd, ERR_NOSUCHNICK(client->getNickName(), arguments[1]));
        }
        else
        {
            channel->sendEveryone(RPL_PRIVMSG(client->getNickName(), channel->GetChannelName(), arguments[2]), client);
        }

    }
    else
    {
        client_to_send = (ClientIrc*)this->FindClientrByNickname(arguments[1]);
        if (client_to_send != NULL)
        {
            if (client_to_send->is_away())
            {
                //to_do 
                this->SendInFd(fd, RPL_AWAY(client->getNickName(), client_to_send->getNickName(), client_to_send->getAmayMsg()));
                //this->SendInFd(client_to_send->getFd(), RPL_PRIVMSG(client->getNickName(), client_to_send->getNickName(), arguments[2]));
            }
            else
            {
                this->SendInFd(client_to_send->getFd(), RPL_PRIVMSG(client->getNickName(), client_to_send->getNickName(), arguments[2]));
            }

        }
    }

}


/*
** Отправляет личное сообщение, не учитывая автоматический ответ
**
** @Command: NOTICE
** @Parameters: <nickname> :<message>
**
*/


void	IrcServer::NOTICE(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;
    ClientIrc   *client_to_send;

    _MainServer->Logger(PURPLE, "Make command NOTIC");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() != 3)
    {
        if (arguments.size() == 2)
        {
            if (arguments[1].find(':') != std::string::npos)
            {
                this->SendInFd(fd, ERR_NORECIPIENT(client->getNickName(), arguments[0]));
            }
            else
            {
                this->SendInFd(fd, ERR_NOTEXTTOSEND(client->getNickName()));
            }
        }
        else
        {
            this->SendInFd(fd, ERR_TOOMANYTARGETS(client->getNickName(), arguments[1]));
        }

    }
    else if (FindClientrByNickname(arguments[1]) == NULL)
    {
        this->SendInFd(fd, ERR_NOSUCHNICK(client->getNickName(), arguments[1]));
    }
    else
    {
        client_to_send = (ClientIrc*)this->FindClientrByNickname(arguments[1]);
        if (client_to_send != NULL)
        {
            this->SendInFd(client_to_send->getFd(), RPL_PRIVMSG(client->getNickName(), client_to_send->getNickName(), arguments[2]));
        }
    }

}



/*
** Отправляет все операм сообщение
**
** @Command: WALLOPS
** @Parameters: <message>
**
*/

void	IrcServer::WALLOPS(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;

    _MainServer->Logger(PURPLE, "Make command WALLOPS");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    if (arguments.size() != 2)
    {
        this->SendInFd(fd, ERR_NEEDMOREPARAMS(client->getNickName(), arguments[0]));
    }
    else
    {

        for (std::vector<ClientIrc *>::iterator start = _operVec.begin(); start != _operVec.end(); start++)
        {
            fd = (*start)->getFd();
            this->SendInFd(fd, RPL_PRIVMSG(client->getNickName(), (*start)->getNickName(), arguments[1]));
        }
    }
}

/*
** Задаю режим опера
** OPER LoginOper PassOper
** 
**
*/

void	IrcServer::OPER(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;

    _MainServer->Logger(PURPLE, "Make command OPER");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() > 2)
    {
        this->SendInFd(fd, ERR_NEEDMOREPARAMS(client->getNickName(), arguments[0]));
    }
    else if (!(std::equal(arguments[0].begin(),arguments[0].end(), LOGIN_OPER)))
        this->SendInFd(fd, ERR_PASSWDMISMATCH(client->getNickName()));
    else if (!(std::equal(arguments[1].begin(),arguments[1].end(), PASS_OPER)))
        this->SendInFd(fd, ERR_PASSWDMISMATCH(client->getNickName()));
    else
    {
        this->SendInFd(fd, RPL_YOUREOPER(client->getNickName()));
        _operVec.push_back(client);
        client->setMode(userOper);
    }
}




static bool    isValidChannel(const std::string& channel)
{
    if (channel[0] != '#')
        return false;

    for (unsigned long i = 1; i < channel.length(); ++i)
    {
        if (!std::isalnum(channel[i]))
            return false;
    }
    return true;
}


/*
 * Добавляет юзера в канал, а если такого канала не существует, создает его
 *
 * @Command: JOIN
 * @Parameters: <channel>{,<channel>} [<key>{,<key>}]
 */

void	IrcServer::JOIN(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;

    _MainServer->Logger(PURPLE, "Make command JOIN");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() != 2)
    {
        this->SendInFd(client->getFd(), ERR_NEEDMOREPARAMS(client->getNickName(), arguments[0]));
    }
    else
    {
        std::vector<std::string>    channelNames = ut::split(arguments[1], ",");
        Channel                     *channel = nullptr;

        /* */
        for (unsigned long i = 0; i < channelNames.size(); i++)
        {
            
            channel = nullptr;
            if (!isValidChannel(channelNames[i]))
            {
                this->SendInFd(client->getFd(), ERR_NOSUCHCHANNEL(client->getNickName(), channelNames[i]));
                continue;
            }

            if ((channel = FindChannelByName(channelNames[i])) == nullptr)
            {
                //TO_DO Добавить логику создания канала
                //std::cout << "names: " << channelNames[i] << std::endl;
                channel = new Channel(channelNames[i], "pass", client, this);
                _Channels.push_back(channel);
                continue;
       
            }

            if (channel->IsByClient(client))
            {
                this->SendInFd(client->getFd(), ERR_USERONCHANNEL(client->getNickName(), client->getNickName(), channel->GetChannelName()));
                continue;
            }

            channel->AddClinet(client);
        }
    }
}


/*
 * Выход из чата
 *
 * @Command: PART
 * @Parameters: 
 */

void	IrcServer::PART(std::vector<std::string> arguments, int fd)
{
    ClientIrc   *client;

    _MainServer->Logger(PURPLE, "Make command PART");

    client = _MainServer->GetClientFromFd(fd);

    if (!client->is_authenticated())
    {
        this->SendInFd(fd, ERR_NOTREGISTERED(client->getNickName()));
    }
    else if (arguments.size() != 2)
    {
        this->SendInFd(fd, ERR_NEEDMOREPARAMS(client->getNickName(), "PART, you can't use ':'"));
    }
    else
    {
        Channel* channel;
        channel = FindChannelByName(arguments[1]);
        
        if (channel == nullptr)
        {
            this->SendInFd(fd, ERR_NOSUCHCHANNEL(client->getNickName(), arguments[1]));
        }
        else
        {
            channel->RemoveClient(client);
        }
    }
}