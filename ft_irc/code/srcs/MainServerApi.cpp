#include <iostream>
#include <ServerApi.hpp>
#include <ServerPoll.hpp>
#include <ServerSelect.hpp>
#include <ServerKqueue.hpp>
#include <ServerEpoll.hpp>
#include <IrcServer.hpp>
#include <Color.hpp>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;    
    
    if (argc > 2)
	{
        IrcServer serv(atoi(argv[1]), argv[2]);
		//ServerSelect  serv("127.0.0.1", atoi(argv[1]));
        //ServerPoll    serv("127.0.0.1", atoi(argv[1]));
        //ServerKqueue  serv("127.0.0.1", atoi(argv[1]));
        //ServerEpoll serv("127.0.0.1", atoi(argv[1]));
        
        // while (1)
        // {
        //     serv.Start();
        // }

        // int events;
        // while (1)
        // {
        //     events = serv.WaitEvent();
        //     int connect = serv.CheckConnect();
        //     if (connect > 0)
        //         continue;
            
        //     connect = serv.CheckDisconnect();
        //     if (connect > 0)

        //         continue;

        //     serv.CheckAndRead();
        // }

        serv.Start();
    }
	else
	{
		std::cout << RED"Use: ircserver <port> <password>\n" << F_NONE;
	}

    return (42);
}