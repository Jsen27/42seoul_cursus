#include "Server.hpp"


int    commander(std::string buffer, int j, int mes, Server &serv)
{
    std::string msg(buffer);
    std::istringstream ss(msg);
    std::string command;
    std::string whatIveDone;
    ss >> command;
    while (ss)
    {
        std::string tmp;
        ss >> tmp;
        whatIveDone += " " + tmp;
    }
    std::cout << "Command: " << whatIveDone << std::endl;
    if (mes == 2 && command != "PASS")
    {
        std::cout << "Error: password not entered!" << std::endl;
        std::string msg = "Password not entered, connection closed!";
        send(j, msg.c_str(), msg.length(), 0);
        close(j);
        serv.getList().erase(j);
        return (1) ;
    }
    if (command == "quit" || command == "QUIT")
        serv.quit(whatIveDone, j);
    else if (command == "NICK" && mes == 3)
        serv.nick(whatIveDone, j, 3);
    else if (command == "USER"  && mes == 4)
        serv.user(whatIveDone, j, 4);
    else if (command == "PASS" && mes == 2)
        serv.pass(whatIveDone, j, 2);
    else if (command == "PING")
        serv.ping(whatIveDone, j);
    else if (command == "WHO")
        serv.who(whatIveDone, j);
    else if (command == "PRIVMSG")
        serv.privmsg(whatIveDone, j);
    else if (command == "JOIN")
        serv.join(whatIveDone, j);
    else if (command == "PART")
        serv.part(whatIveDone, j);
    else if (command == "KICK")
        serv.kick(whatIveDone, j);
    else if (command == "TOPIC")
        serv.topic(whatIveDone, j);
    else if (command == "INVITE")
        serv.invite(whatIveDone, j);
    else if (command == "INSULTA" || command == "insulta" || command == "INSULTAMI" || command == "insultami")
        serv.insulta(whatIveDone, j);
    else if (command == "SECRET" || command == "secret")
        serv.secret(whatIveDone, j);
    else if (command == "channels" || command == "CHANNELS")
        serv.channel(whatIveDone, j);
    else if (command == "MODE")
        serv.mode(whatIveDone, j);
    return (0);
}

int cycle(Server &serv)
{
    int flags = fcntl(serv.getServerSock(), F_GETFL, 0);
    fcntl(serv.getServerSock(), F_SETFL, flags | O_NONBLOCK);
    struct pollfd fds[512];
    fds[0].events = POLLIN;
    fds[0].fd = serv.getServerSock();
    fds[0].revents = 0;
    int ret = 0;
    while (1)
    {
        ret = poll(fds, serv.getList().size() + 1, -1);
        if (ret < 0)
        {
            perror("poll failed");
            break;
        }
        // Check if there is new client to accept
        if (fds[0].revents && POLLIN)
        {
            int clientsockfd = accept(serv.getServerSock(), NULL, NULL);
            if (clientsockfd < 0)
            {
                std::cout << "Accept failed!" << std::endl;
                if (errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    std::cout << "Error: continue" << errno << std::endl;
                    continue;
                }
                else
                {
                    std::cout << "Error: break" << errno << std::endl;
                    exit(0);
                }
            }
            std::map<int, User>::iterator it = serv.getList().begin();
            serv.getList().insert(std::pair<int, User>(clientsockfd, User()));

            // Initialize client for polling
            int n = serv.getList().size();
            fds[n].fd = clientsockfd;
            fds[n].events = POLLIN;
            fds[n].revents = 0;
            serv.getList()[clientsockfd].setSocket(clientsockfd);
            serv.getList()[clientsockfd].setMessages(0);
            serv.getList()[clientsockfd].setNickname("");
            serv.getList()[clientsockfd].setUsername("");
            serv.getList()[clientsockfd].setPassword("");

            std::cout << "Accept created!" << std::endl;
        }

        // Process events from existing clients
        for (int j = 1; j <= (serv.getList().size()); j++)
        {
            if (fds[j].revents && POLLIN)
            {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                ret = recv(fds[j].fd, buffer, sizeof(buffer), 0);
                if (ret == -1)
                {
                    std::cout << "Recv failed!" << std::endl;
                    if (errno == EAGAIN || errno == EWOULDBLOCK)
                    {
                        std::cout << "Error: continue" << errno << std::endl;
                        continue;
                    }
                    else
                    {
                        close(fds[j].fd);
                        serv.getList().erase(fds[j].fd);
                        std::cout << errno << std::endl;
                        return 0;
                    }
                }
                else if (ret == 0)
                {
                    std::cout << "Client disconnected!" << std::endl;
                    serv.ft_delete_user(fds[j].fd);
                    serv.getList().erase(fds[j].fd);
                    close(fds[j].fd);
                }
                else
                {
                    buffer[ret] = '\0';
                    std::cout << "Received: " << buffer << std::endl;
                    serv.getList()[fds[j].fd].setMessages(serv.getList()[fds[j].fd].getMessages() + 1);
                }
                if (commander(buffer, fds[j].fd, serv.getList()[fds[j].fd].getMessages(), serv))
                    break;
            }
        }
    }
    return 0;
}
