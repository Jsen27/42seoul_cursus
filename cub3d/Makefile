NAME = cub3D

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = make -C libft

SRCS = 	main.c \
		ray_casting/draw_camera.c \
		ray_casting/event.c \
		ray_casting/load_texture.c \
		ray_casting/raycasting.c \
		ray_casting/set_camera.c \
		ray_casting/init_info.c \
		parsing/get_map.c \
		parsing/get_util.c \
		parsing/get_file.c \
		parsing/get_element.c \
		parsing/parse_rgb.c \
		parsing/get_texture_path.c \
		parsing/check_world_map.c \

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