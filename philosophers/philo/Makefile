NAME =	philo

CFLAGS =	-Wall -Wextra -Werror -fsanitize=thread -g

SRCS =	init.c\
		main.c\
		start_philo.c\
		utils.c\
		check_finish.c\

OBJS =	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) philo

re	:	fclean 
		make all

.PHONY	:	all clean fclean re