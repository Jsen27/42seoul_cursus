NAME =	push_swap

CFLAGS =	-Wall -Wextra -Werror

LIBFT =	make -C libft

SRCS =	check_arg.c\
		main.c\
		make_array.c\
		make_stack.c\
		move_stack.c\
		operation.c\
		sort_algorithm.c\
		sort_min.c\
		sort_radix.c\

OBJS =	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
			$(RM) $(OBJS)
			make -C libft clean
fclean	:	clean
			$(RM) push_swap libft/libft.a

re	:	fclean 
		make all

.PHONY	:	all clean fclean re