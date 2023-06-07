#ifndef FT_CLIENTIRC
# define FT_CLIENTIRC


class Client
{
	public:

		/* Constructor */
		Client(int fd_client, sockaddr_in 	addrinfo_client, std::string server_ipaddr)
		{
			_fd = fd_client;
			_addrinfo = addrinfo_client;
			_server_ipaddr = server_ipaddr;
            GetNameInfo((sockaddr *)&addrinfo_client);
                    
		};

		int getFd() const
		{ 
			return (_fd);
		}

        void GetNameInfo(const sockaddr * clientaddr)
        {
            char 				hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
            //socklen_t           addrlen;         /* input */

            if (getnameinfo(clientaddr, sizeof (struct sockaddr), hbuf, sizeof(hbuf), sbuf, sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV))
            {
               printf("Error!\n");
            }
            //printf("host=%s, serv=%s\n", hbuf, sbuf);
            std::string			hosts(hbuf);
            _host  = hosts;
        }



		struct sockaddr_in getAddrInfo() const
		{
			return (_addrinfo);
		}
	protected:
		struct sockaddr_in 	_addrinfo;
		int					_fd;
		std::string			_server_ipaddr;
        std::string         _host;


};

enum UserMode
{
    UserNone = 0,					// 0000000000
    invisibility = 1 << 0,          // 0000000001
    silence = 1 << 1,          		// 0000000010
    userOper = 1 << 2,				// 0000000100
    wallopsOff = 1 << 3,       		// 0000001000

    /* Other */
};


/* Клиенты IRC Сервера */
class ClientIrc: public Client
{
    public:

        /* Constructor */
        ClientIrc(int fd_client, sockaddr_in 	addrinfo_client, std::string server_ipaddr): Client(fd_client, addrinfo_client, server_ipaddr)
        {
            std::string user("user_");

            _name = "";
            //_name = user + std::to_string(fd_client);
            _nickname = _name;
            _realname = "None";
            _isconnect = false;
            _auntificated = false;
        };


        std::string getInfoClient()
        {
            std::string str;
            //char ip4[INET_ADDRSTRLEN]; // место для строки IPv4
            int port;

            port =  ntohs((&_addrinfo)->sin_port);
           // inet_ntop(AF_INET, &((&_addrinfo)->sin_addr), ip4, INET_ADDRSTRLEN);//заполнили ip

            str += "<-----Client Info----->\n";
            str += "Server IP Adress: " + _server_ipaddr + "\n";
            str += "Port: " + std::to_string(port) + "\n";
            str += "Name: " + getName() + "\n"; 
            return  (str);
        }

        std::string getName(){return (_name);} 
        std::string getNickName(){return (_nickname);} 
        std::string getAmayMsg(){return _awayMessage;}
        std::string getFullname() const { return this->_nickname + '!' + this->_nickname + '@' + _host;}
        void setName(std::string  name){this->_name = name;}
        void SetNickName(std::string &name){this->_nickname = name;}
        void SetRealName(std::string &name){this->_realname = name;}
        void ChangeStatusConnect(){_isconnect = true;}
        void ChangeStatusAuthenticated(){_auntificated = true;}
        bool is_connected(){return (_isconnect);}
        bool is_authenticated(){return (_auntificated);}
        bool is_away(){return (!_awayMessage.empty());}
        void SetAwayMsg(std::string msg){_awayMessage = msg;}



        void                setMode(UserMode flag)
        {
            this->_modes |= flag;
        }

        void                unsetMode(UserMode flag)
        {
            this->_modes &= (~flag);
        }
        
        bool                hasMode(UserMode flag) const
        {
            return ((_modes & flag) == flag);
        }
        
        // std::string         showMode() const;


    private:
        std::string    _name;
        std::string    _username;
        std::string    _realname;
        std::string    _nickname;
        std::string    _awayMessage;
        int            _modes;
        bool           _isconnect; /* If succsecc password */
        bool           _auntificated;

};
 
#endif

// USER ifanzilka2 * 127.0.0.1 :Fanzil2
// NICK fanzil2