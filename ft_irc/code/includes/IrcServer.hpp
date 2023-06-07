#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

#include "ServerApi.hpp"
#include <ServerPoll.hpp>
#include <ServerSelect.hpp>
#include <ServerKqueue.hpp>
#include <ServerEpoll.hpp>
#include "utility.hpp"
#include "Channel.hpp"
#include "IrcServerProtocol.hpp"

// #define SELECT  0
// #define POLL    1
// #define EPOLL   2
// #define KQUEUE  3

#define LOGIN_OPER "admin"
#define PASS_OPER "admin"

#define DELIMETER_COMAND "\n"

class Channel;

class IrcServer
{
    public:

        /* Constructors */
        IrcServer(int port, std::string password);

		IrcServer(std::string &ipaddr, int port, std::string password);

		IrcServer(const char *ipaddr, int port,std::string password);

        /* Destructor */
        ~IrcServer();

        /* Function Main Server */

        int     WaitEvent();
        int     CheckConnect();
        int     CheckDisconnect();
        int     CheckAndRead();
        int     SendInFd(int fd, std::string msg);
        void    Start();

        

        bool    CheckPassword(std::string &str);
        void    ChangeClientStatus(int fd);
        void    ParseMessage(int fd);
        void    MakeComand(std::vector<std::string> &arguments, int fd);


        Client*       FindClientrByNickname(const std::string& nickname);
        Channel*      FindChannelByName(const std::string& name);


        void    WelcomeUser(ClientIrc *client, int fd);
        void	PASS(std::vector<std::string> arguments, int fd);
        void	USER(std::vector<std::string> arguments, int fd);
        void	NICK(std::vector<std::string> arguments, int fd);
        void	QUIT(std::vector<std::string> arguments, int fd);
        void	PING(std::vector<std::string> arguments, int fd);
        void	AWAY(std::vector<std::string> arguments, int fd);
        void	PRIVMSG(std::vector<std::string> arguments, int fd);
        void	NOTICE(std::vector<std::string> arguments, int fd);
        void	WALLOPS(std::vector<std::string> arguments, int fd);
        void	OPER(std::vector<std::string> arguments, int fd);
        void	JOIN(std::vector<std::string> arguments, int fd);
        void	PART(std::vector<std::string> arguments, int fd);

        
        
    protected:
        /* Делаю сокращение */
        typedef	void (IrcServer::*commandPtr)(std::vector<std::string>, int);
        std::map<std::string, commandPtr>   _commands;

        /* Главный сервер для работы с сокетами */
        AbstractServerApi           *_MainServer;


        /* Чаты */
        std::vector<Channel *>     _Channels;
        
        /* Клинты которые как оперы */
        std::vector<ClientIrc *>    _operVec;


        //std::vector<Channel>   _channels;
        std::string        _pass;
        std::string        _pass_hash;

    private:

        void InitComands();
        void InitIRC(std::string password, std::string ipaddr, int port);

};

#endif
