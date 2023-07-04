#ifndef SERVER_HPP
# define SERVER_HPP

# define PORT_MIN 1024
# define PORT_MAX 65535
# define LEN_MIN_PASS 8
# define TIMEOUT 0
# define MAX_CLIENTS 42
# define CHECK_PASS -42
# define EMPTY ""

# include "./ircserv.hpp"

class Server : public Command {
	public:
								Server(void);
								Server(char *port_to_use, char *pass_to_use);
								Server(const Server &other_serv);
		Server					&operator=(const Server &other_serv);
								~Server(void);

		int						getPort(void)const;
		std::string				getPass(void)const;
		int						getSock(void)const;
		std::vector<pollfd>		getStby(void)const;

		void					setPort(char *port_to_use);
		void					setPass(char *pass_to_use);

		void					init_sock(void);
		void					run(void);
		void					create_client(void);
		bool					check_pass(int i, int cfd);
		bool					create_user(std::vector<std::string> input, int cfd);
		std::string				handle_client(int i, int &cfd);
		void					init_client(int i, int cfd);
		std::string				get_input(int i, int &cfd, bool reset);
		void					display_logs(std::vector<std::string> &cmd, int i, int cfd);

	private:
		int						port;
		std::string				pass;
		int						sock;
		std::vector<pollfd>		stby;
};

#endif
