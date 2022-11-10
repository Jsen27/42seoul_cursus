NAME		= libft.a

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_strlen.c		\
				ft_strlcpy.c		\
				ft_strlcat.c		\
				ft_strchr.c		\
				ft_strnstr.c		\
				ft_strncmp.c		\
				ft_strdup.c		\
				ft_strrchr.c		\
				ft_striteri.c		\
				ft_memset.c		\
				ft_memcpy.c		\
				ft_memmove.c		\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_bzero.c		\
				ft_atoi.c		\
				ft_calloc.c		\
				ft_isalnum.c		\
				ft_isalpha.c		\
				ft_isascii.c		\
				ft_isdigit.c		\
				ft_isprint.c		\
				ft_strdup.c		\
				ft_tolower.c		\
				ft_toupper.c		\
				ft_substr.c		\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c		\
				ft_strmapi.c		\
				ft_itoa.c		\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\

SRCS_BONUS	= ft_lstnew_bonus.c		\
				ft_lstsize_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstadd_back_bonus.c	\
				ft_lstclear_bonus.c	\
				ft_lstlast_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\
				ft_lstdelone_bonus.c	\

OBJS		= $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all:		$(NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ_FILES)
				ar crs $(NAME) $(OBJ_FILES)

bonus :
			make WITH_BONUS=1 all

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		bonus all clean fclean re