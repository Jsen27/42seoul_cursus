CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs

SOURCES = $(SRCS)/calculator.c $(SRCS)/ft_atoi.c $(SRCS)/main.c $(SRCS)/modulo.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -f
NAME = do-op

INC = $(SRCS)/ft.h

all : $(NAME)
    
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -I $(INC)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
.PONY : all fclean clean do-op
