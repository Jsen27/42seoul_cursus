/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:48:19 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/18 14:54:21 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define WIDTH 640
# define HEIGHT 480
# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define K_AR_L 123
# define K_AR_R 124
# define K_ESC 53
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

typedef struct s_camera
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheight;
	int		wallstart;
	int		wallend;
	int		texnum;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}	t_camera;

typedef struct s_element
{
	char	*east_path;
	char	*west_path;
	char	*south_path;
	char	*north_path;
	int		floor_color[3];
	int		ceil_color[3];
}	t_element;

typedef struct s_map
{
	char	**map;
	char	start_direction;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_info
{
	t_element	element;
	t_map		map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	t_img		img;
	int			buf[HEIGHT][WIDTH];
	int			texture[4][64][64];
	double		movespeed;
	double		rotspeed;
}	t_info;

int		main_loop(t_info *info);
int		key_press(int key, t_info *info);
int		redcross(int key_code, void *data);
void	set_camera(t_info *info, t_camera *cam, int x);
void	draw_camera(t_info *info, t_camera *cam, int x);
void	load_texture(t_info *info);
void	get_element(int fd, t_info *info);
void	get_map(int fd, t_info *info);
void	get_file(char *map_path, t_info *info);
void	my_error(void);
void	init_info(char direction, t_info *info);
void	parse_rgb(char *str, int *color_store);
void	check_str_count(char **p_str, int count);
void	get_texture_path(t_element *e, char *str, int *flag);
void	check_world_map(char **map);

#endif
