/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:48:19 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/17 21:29:54 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "key_macos.h"
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define WIDTH 640
# define HEIGHT 480

typedef struct s_camera
{
	double	camera_x;//평면카메라
	double	raydir_x;//카메라 방향벡터
	double	raydir_y;
	int		map_x;//플레이어 좌표 (부딪힌 벽의 좌표를 저장할 때 사용)
	int		map_y;
	double	sidedist_x;//처음 만나는 벽의 거리
	double	sidedist_y;
	double	deltadist_x;//다음 만나는 벽의 거리
	double	deltadist_y;
	double	perwalldist;//어안렌즈 현상 보정
	int		step_x;//벽이 있는지 검사 할 방향 (광선의 방향에 따라 이동방향(음or양)을 담음)
	int		step_y;
	int		hit;//벽에 부딪히면 1, 아니면 0 flag
	int		side;//y축에 수직이면 1(-), x축에 수직이면 0(ㅣ) flag
	int		lineheight;//벽의 높이
	int		wallstart;//벽의 시작점과 끝점
	int		wallend;
	int		texnum;//텍스쳐
	double	wall_x;//벽의 X축부터 광선이 부딪힌 곳의 거리
	int		tex_x;//텍스쳐끝에서 광선까지의 픽셀 거리
	int		tex_y;
	double	tex_pos;//텍스쳐에서 어떤 색상을 가져올지에 대한 y좌표
	double	step;//텍스쳐의 원래 크기를 실제 벽의 크기로 나눈 값
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

#endif
