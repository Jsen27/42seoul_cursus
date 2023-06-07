#include "Channel.hpp"

/* Constructor */
Channel::Channel(std::string name, std::string pass, ClientIrc * main_client,IrcServer *ircservr)
{
    _IrcServer = ircservr;
    _channelName = name;
    _pass = pass;
    _clients.push_back(main_client);
    _opers.push_back(main_client);
    _topic = "Welcome to ifanzilka IrcChannel";
    FirstMessage(main_client);
}


/* Добавление клиента в канал */
void Channel::AddClinet(ClientIrc *client)
{
    _clients.push_back(client);
    FirstMessage(client);
}

/* Удаляю клиента и говорю все что я вышел */
void Channel::RemoveClient(ClientIrc *client)
{
    if(!IsByClient(client))
    {
        _IrcServer->SendInFd(client->getFd(), ERR_NOTONCHANNEL(client->getNickName(),this->GetChannelName()));
    }
    else
    {
        _clients.erase(std::find(_clients.begin(), _clients.end(), client));
        sendEveryone(RPL_PART(client->getNickName(), this->GetChannelName(), "QUITED"), nullptr);
    }
}


void Channel::AddOper(ClientIrc *client)
{
    _opers.push_back(client);
}

void Channel::RemoveOper(ClientIrc *client)
{
    _opers.erase(std::find(_opers.begin(), _opers.end(), client));
}

/* Проверка на то что клиент есть в канале */
bool    Channel::IsByClient(ClientIrc *client)
{
    if (std::find(_clients.begin(), _clients.end(), client) != _clients.end())
    {
        return true;
    } 
    return false;

}

bool    Channel::IsByOper(ClientIrc *client)
{
    if (std::find(_opers.begin(), _opers.end(), client) != _opers.end())
    {
        return true;
    } 
    return false;
}

/* Отправка сообщения всем клиентам */
void Channel::sendEveryone(std::string const &send, ClientIrc * sendUser)
{
    if(!IsByClient(sendUser) && sendUser != nullptr)
    {
        _IrcServer->SendInFd(sendUser->getFd(), ERR_NOTONCHANNEL(sendUser->getNickName(),this->_channelName));
    }
    
    
    for(std::vector<ClientIrc*>::iterator    iterClient = _clients.begin(); iterClient != _clients.end(); ++iterClient)
    {
        if(*iterClient != sendUser)
        {
            //придет define
            _IrcServer->SendInFd((*iterClient)->getFd(), send);
        }
    }

}

void    Channel::kickUser(ClientIrc *CallClient, ClientIrc *client, std::string &comment)
{
    if (!IsByOper(CallClient))
    {
        _IrcServer->SendInFd(CallClient->getFd(), ERR_CHANOPRIVSNEEDED(CallClient->getNickName(),this->_channelName));
    }
    else if (!IsByClient(client))
    {
        _IrcServer->SendInFd(CallClient->getFd(), ERR_NOSUCHNICK(CallClient->getNickName(),this->_channelName));
    }
    else
    {
        sendEveryone(RPL_KICK(CallClient->getNickName(), this->_channelName, client->getNickName(), comment), nullptr);
        RemoveClient(client);
    }
}

std::string Channel::GetChannelName()
{
    return (_channelName);
}


std::string Channel::GetTopic()
{
    return (_topic);
}

/* Показываю топик канала */
void    Channel::displayTopic(ClientIrc *client)
{
    if(_topic.empty())
    {
        _IrcServer->SendInFd(client->getFd(), RPL_NOTOPIC(client->getNickName(), this->_channelName));
    }
    else
    {
        _IrcServer->SendInFd(client->getFd(), RPL_TOPIC(client->getNickName(), this->_channelName, _topic));
    }
}

/* Отправка клиенту списка тех кто есть в канале */
void Channel::sendNamesOnline(ClientIrc *client)
{

    if (!IsByClient(client))
    {
        _IrcServer->SendInFd(client->getFd(), ERR_NOTONCHANNEL(client->getNickName(), this->GetChannelName()));
    }
    else
    {
        for (std::vector<ClientIrc *>::iterator Client_iter = _clients.begin(); Client_iter != _clients.end(); Client_iter++)
        {
            _IrcServer->SendInFd(client->getFd(), RPL_NAMREPLY(client->getNickName(), this->GetChannelName(), (*Client_iter)->getFullname()));
        }
            _IrcServer->SendInFd(client->getFd(), RPL_ENDOFNAMES(client->getNickName(), this->GetChannelName()));
    }
}


/* Приветвенное сообщение при поключение и расыылка всем твоего статуса */
void    Channel::FirstMessage(ClientIrc *client)
{
    sendEveryone(RPL_JOIN(client->getFullname(), this->_channelName), nullptr);
    displayTopic(client);
    for (std::vector<ClientIrc *>::iterator Client_iter = _clients.begin(); Client_iter != _clients.end(); Client_iter++)
    {
        sendNamesOnline(*Client_iter);
    }

}

/* Destructor */
Channel::~Channel()
{
    //pass
}