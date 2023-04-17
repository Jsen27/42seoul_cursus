NAME = cub3d

CFLAGS = -fsanitize=address -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -g

LIBFT = make -C libft

SRCS = 	draw_camera.c \
		event.c \
		parsing/get_map.c \
		parsing/get_util.c \
		parsing/get_file.c \
		parsing/get_element.c \
		load_texture.c \
		main.c \
		raycasting.c \
		set_camera.c \
		init_info.c \

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIBFT)
			$(CC) $(MLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
			$(RM) $(OBJS)
			make -C libft clean
fclean	:	clean
			$(RM) cub3d libft/libft.a

re	:	fclean all

.PHONY	:	all clean fclean re