NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FUNC = ft_printf\
	   ft_printf_hex\
	   ft_printf_ptr\
	   ft_printf_util\
	   ft_putnbr

SRCS = $(addsuffix .c, $(FUNC))
OBJS = $(addsuffix .o, $(FUNC))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(AR) $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY : bonus all clean fclean re