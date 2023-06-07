#ifndef IRCSERVER
# define IRCSERVER

#include <IrcServer.hpp>

/* Constructos */

IrcServer::IrcServer(int port, std::string password)
{
    std::string tmp = "127.0.0.1";
            
    IrcServer::InitIRC(password, tmp, port);

}


IrcServer::IrcServer(std::string &ipaddr, int port, std::string password)
{
    IrcServer::InitIRC(password, ipaddr, port);
}


IrcServer::IrcServer(const char *ipaddr, int port,std::string password)
{
    std::string tmp = std::string(ipaddr);;

    IrcServer::InitIRC(password, tmp, port);
}

/* Destructor */

IrcServer::~IrcServer()
{
    delete _MainServer;
}

void IrcServer::InitComands()
{
    _commands["PASS"] = &IrcServer::PASS;
    _commands["USER"] = &IrcServer::USER;
    _commands["NICK"] = &IrcServer::NICK;
    _commands["QUIT"] = &IrcServer::QUIT;
    _commands["PING"] = &IrcServer::PING;
    _commands["AWAY"] = &IrcServer::AWAY;
    _commands["PRIVMSG"] = &IrcServer::PRIVMSG;
    _commands["NOTICE"] = &IrcServer::NOTICE;
    _commands["WALLOPS"] = &IrcServer::WALLOPS;
    _commands["OPER"] = &IrcServer::OPER;
    _commands["JOIN"] = &IrcServer::JOIN;
    _commands["PART"] = &IrcServer::PART;
}


void IrcServer::InitIRC(std::string password, std::string ipaddr, int port)
{

    // _MainServer = new ServerSelect(ipaddr, port);
    //_MainServer = new ServerPoll(ipaddr, port);
    // _MainServer = new ServerKqueue(ipaddr, port);
    // _MainServer = new ServerEpoll(ipaddr, port);

    #if defined(SELECT)
        _MainServer = new ServerSelect(ipaddr, port);
        _MainServer->Logger(GREEN, std::string("Server Type Select"));
    #elif defined(POLL)
        _MainServer = new ServerPoll(ipaddr, port);
        _MainServer->Logger(GREEN, std::string("Server Type Poll"));
    #elif defined(EPOLL)
        _MainServer = new ServerEpoll(ipaddr, port);
        _MainServer->Logger(GREEN, std::string("Server Type Epoll"));
    #else
        _MainServer = new ServerKqueue(ipaddr, port);
        _MainServer->Logger(GREEN, std::string("Server Type Kqueue"));
    #endif

    
    InitComands();
    _pass = password;
}


int IrcServer::WaitEvent()
{
    int res_return;

    res_return = _MainServer->WaitEvent();
    return (res_return);
}

int IrcServer::CheckConnect()
{
    int res_return;

    res_return = _MainServer->CheckConnect();
    return (res_return);
}

int IrcServer::CheckDisconnect()
{
    int res_return;

    res_return = _MainServer->CheckDisconnect();
    return (res_return);
}

int IrcServer::CheckAndRead()
{
    ClientIrc   *Client;
    int         fd;

    fd = _MainServer->CheckAndRead();
    if (fd > 1)
    {
        Client = _MainServer->GetClientFromFd(fd);
        
        if (Client != NULL)
        {
            _MainServer->Logger(B_GRAY, "\n[" + Client->getName() + "] " + _MainServer->_msg);
        }
        _MainServer->Logger(B_GRAY, "Read in " + std::to_string(fd) + " fd");
    }
    return (fd);
}

int IrcServer::SendInFd(int fd, std::string msg)
{
    ClientIrc  *client;
    int     res;

    client = _MainServer->GetClientFromFd(fd);
    if (client == NULL)
        return (0);

    std::cout << "\n";
    _MainServer->Logger(PURPLE, std::string("[") + client->getNickName() + "] " + std::string("Attempt to send: "));
	_MainServer->Logger(B_BLUE, msg);
    std::cout << "\n";
    
    msg += "\r\n";
    res = _MainServer->SendInFd(fd, msg);
    //res = _MainServer->SendInFd(fd, "\n\r");
    return (res);
}

void IrcServer::Start()
{
    int     events;
    int     connect;
    int     disconnect;
    int     reads_fd;
    
    events = this->WaitEvent();
    while (1)
    {
        _MainServer->_msg="";
        if (events == 0)
            events = this->WaitEvent();

        connect = this->CheckConnect();
        if (connect > 0)
        {
            events--;
            continue;
        }
            

        disconnect = this->CheckDisconnect();
        if (disconnect > 0)
        {
            events--;
            continue;
        }
            

        reads_fd = this->CheckAndRead();
        if (reads_fd > 1)
        {
            this->ParseMessage(reads_fd);
            events--;
        }
        
    }
    
}


bool IrcServer::CheckPassword(std::string &str)
{
    if (_pass == str)
        return (true);
    return (false);
}


void  IrcServer::ChangeClientStatus(int fd)
{
    ClientIrc* clinet = _MainServer->GetClientFromFd(fd);

    if (clinet != NULL)
    {
        clinet->ChangeStatusConnect();
        _MainServer->Logger(GREEN, "Status client is changed");
    }
}

void    IrcServer::ParseMessage(int fd)
{
    _MainServer->Logger(B_GRAY, "Parse msg...");

    std::vector<std::string> comands = ut::split(_MainServer->_msg, DELIMETER_COMAND); 
    std::vector<std::string> arguments;

    for (unsigned int i = 0; i < comands.size(); i++)
    {
        if (comands[i] != "")
        {
            ut::ProcessingStr(comands[i]);

            //std::cout << "cmd start\n" << std::endl;        
            std::vector<std::string> arguments = ut::splitForCmd(comands[i]);
            MakeComand(arguments, fd);
    
        }

    }
    _MainServer->_msg = "";
}

void    IrcServer::MakeComand(std::vector<std::string> &arguments, int fd)
{
    if (_commands.find(arguments[0]) != _commands.end())
    {
        (this->*_commands[arguments[0]])(arguments, fd);
    }
}

Client*     IrcServer::FindClientrByNickname(const std::string& nickname)
{
    
    std::vector<ClientIrc*>::iterator iter_begin = _MainServer->_Clients.begin();
    std::vector<ClientIrc*>::iterator iter_end = _MainServer->_Clients.end();

    while (iter_begin < iter_end)
    {
        
        if (nickname == (*iter_begin)->getNickName())
        {
            return ((*iter_begin));
        }

        iter_begin++;
    }
    return (NULL);
}

Channel*      IrcServer::FindChannelByName(const std::string& name)
{
    std::vector<Channel*>::iterator iter_begin = _Channels.begin();
    std::vector<Channel*>::iterator iter_end = _Channels.end();

    while (iter_begin < iter_end)
    {
        
        if (name == (*iter_begin)->GetChannelName())
        {
            return ((*iter_begin));
        }

        iter_begin++;
    }
    return (NULL);
}

# endif