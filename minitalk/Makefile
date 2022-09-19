CLIENT_SRC = client.c
SERVER_SRC = server.c

CLIENTNAME = client
SERVERNAME = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = make -C libft
PRINTF = make -C ft_printf

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

all : $(CLIENTNAME) $(SERVERNAME)

$(CLIENTNAME) :	$(CLIENT_OBJ)
				$(LIBFT)
				$(PRINTF)
				$(CC) $(CFLAGS) -o $(CLIENTNAME) $(CLIENT_OBJ) libft/libft.a ft_printf/libftprintf.a

$(SERVERNAME) : $(SERVER_OBJ)
				$(CC) $(CFLAGS) -o $(SERVERNAME) $(SERVER_OBJ) libft/libft.a ft_printf/libftprintf.a

clean :
		$(RM) server.o client.o
		make -C libft clean
		make -C ft_printf clean
fclean : clean
		$(RM) server client libft/libft.a ft_printf/libftprintf.a

re : fclean all

.PHONY : all clean fclean re