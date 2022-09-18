CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

all : client server

client : client.o libft printf
		$(CC) $(CFLAGS) -c -o $@ $< -L libft -lft -L ft_printf -lft
server : server.o libft printf
		$(CC) $(CFLAGS) -c -o $@ $< -L libft -lft -L ft_printf -lft

.o : .c
		$(CC) -c $(CFLAGS) $<

libft :
		make -C libft
printf :
		make -C ft_printf

clean :
		$(RM) server.o client.o
		make -C libft clean
		make -C ft_printf clean
fclean : clean
		$(RM) server client libft/libft.a ft_printf/libftprintf.a

re : fclean all

.PHONY : all clean fclean re libft printf