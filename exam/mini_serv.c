#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <sys/socket.h>

typedef struct s_client
{
	int id;
	char msg[110000];
} t_client;

t_client client[1024];
fd_set current_fd, read_fd, write_fd;
int max = 0, next_id = 0;
char buffer_read[4096 * 42], buffer_write[4096 * 42];

void error(char *err)
{
	write(2, err, strlen(err));
	write(2, "\n", 1);
	exit(1);
}

void send_all(int sender)
{
	for (int sockfd = 0; sockfd <= max; sockfd++)
		if (FD_ISSET(sockfd, &write_fd) && sockfd != sender)
			send(sockfd, buffer_write, strlen(buffer_write), 0);
}

int main(int ac, char** av)
{
	if (ac != 2)
		error("Wrong number of arguments");
	
	int master_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (master_sock < 0)
		error("Fatal error");

	bzero(&client, sizeof(client));
	FD_ZERO(&current_fd);
	
	FD_SET(master_sock, &current_fd);
	max = master_sock;

	struct sockaddr_in addr;
	socklen_t addrlen = sizeof(addr);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433);
	addr.sin_port = htons(atoi(av[1]));

	if (bind(master_sock, (struct sockaddr*)&addr, addrlen) < 0)
		error("Fatal error");
	if (listen(master_sock, 42) < 0)
		error("Fatal error");

	while (1)
	{
		read_fd = write_fd = current_fd;
		if (select(max + 1, &read_fd, &write_fd, NULL, NULL) < 0)
			continue;
		for (int sockfd = 0; sockfd <= max; sockfd++)
		{
			if (FD_ISSET(sockfd, &read_fd) && sockfd == master_sock)
			{
				int new_fd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
				if (new_fd < 0)
					continue;
				FD_SET(new_fd, &current_fd);
				client[new_fd].id = next_id++;
				max = max > new_fd ? max : new_fd;
				sprintf(buffer_write, "server: client %d just arrived\n", client[new_fd].id);
				send_all(new_fd);
				break;
			}
			else if(FD_ISSET(sockfd, &read_fd))
			{
				int res = recv(sockfd, buffer_read, 65000, 0);
				if (res <= 0)
				{
					sprintf(buffer_write, "server: client %d just left\n", client[sockfd].id);
					send_all(sockfd);
					FD_CLR(sockfd, &current_fd);
					close(sockfd);
					break;
				}
				else
				{
					for (int i = 0, j = strlen(client[sockfd].msg); i < res; i++, j++)
					{
						client[sockfd].msg[j] = buffer_read[i];
						if (client[sockfd].msg[j] == '\n')
						{
							client[sockfd].msg[j] = '\0';
							sprintf(buffer_write, "client %d: %s\n", client[sockfd].id, client[sockfd].msg);
							send_all(sockfd);
							bzero(&client[sockfd].msg, strlen(client[sockfd].msg));
							j = -1;
						}
					}
					break;
				}
			}
		}
	}
}