#ifndef CHANNELS_HPP
# define CHANNELS_HPP

#include "IrcServer.hpp"
#include "IrcServerProtocol.hpp"

class IrcServer;


/* Каналы внутри IRC Сервера*/
class Channel
{
    private:
        IrcServer                               *_IrcServer;
        std::string                             _channelName;
        std::string                             _topic;
        std::string                             _pass;
        std::vector<ClientIrc *>                _clients;
        std::vector<ClientIrc *>                _opers;

    public:
        Channel(std::string name, std::string pass, ClientIrc *main_client, IrcServer *ircservr);
        ~Channel();


        void    AddClinet(ClientIrc *client);
        void    RemoveClient(ClientIrc *client);
        
        void    AddOper(ClientIrc *client);
        void    RemoveOper(ClientIrc *client);

        /* Check clinet in channel */
        bool    IsByClient(ClientIrc *client);
        bool    IsByOper(ClientIrc *client);

        void    sendEveryone(std::string const &send, ClientIrc * sendUser);
        void    kickUser(ClientIrc *callClient, ClientIrc *client, std::string &comment);

        std::string GetChannelName();
        std::string GetTopic();

        void    displayTopic(ClientIrc *cleint);
        void    FirstMessage(ClientIrc *cleint);
        void    sendNamesOnline(ClientIrc *client);
        
        //std::string getChannelName(); 


};


#endif