NAME = so_long

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = make -C libft

SRCS = 	action.c\
		main.c\
		put_image.c\
		read_file.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIBFT)
			$(CC) $(MLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
			$(RM) $(OBJS)
			make -C libft clean
fclean	:	clean
			$(RM) so_long libft/libft.a

re	:	fclean all

.PHONY	:	all clean fclean re