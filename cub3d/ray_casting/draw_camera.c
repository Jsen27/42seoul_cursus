/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:55:30 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/18 11:30:19 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_texture(t_info *info, t_camera *cam, int x)
{
	int	color;

	if (cam->side == 0)
		cam->wall_x = info->pos_y + cam->perwalldist * cam->raydir_y;
	else
		cam->wall_x = info->pos_x + cam->perwalldist * cam->raydir_x;
	cam->wall_x -= floor(cam->wall_x);
	cam->tex_x = (int)(cam->wall_x * (double)TEXWIDTH);
	if (cam->side == 0 && cam->raydir_x > 0)
		cam->tex_x = TEXWIDTH - cam->tex_x - 1;
	if (cam->side == 1 && cam->raydir_y < 0)
		cam->tex_x = TEXWIDTH - cam->tex_x - 1;
	cam->step = 1.0 * TEXHEIGHT / cam->lineheight;
	cam->tex_pos = (cam->wallstart - HEIGHT
			/ 2 + cam->lineheight / 2) * cam->step;
	while (cam->wallstart < cam->wallend)
	{
		cam->tex_y = (int)cam->tex_pos & (TEXHEIGHT - 1);
		cam->tex_pos += cam->step;
		color = info->texture[cam->texnum][cam->tex_y][cam->tex_x];
		info->buf[cam->wallstart][x] = color;
		cam->wallstart++;
	}
}

static void	sel_texture(t_camera *cam)
{
	cam->texnum = 0;
	if (cam->side == 0)
	{
		if (cam->raydir_x < 0)
			cam->texnum = 2;
		else
			cam->texnum = 3;
	}
	else
	{
		if (cam->raydir_y < 0)
			cam->texnum = 0;
		else
			cam->texnum = 1;
	}
}

static void	set_wallpos(t_camera *cam)
{
	cam->lineheight = (int)(HEIGHT / cam->perwalldist);
	cam->wallstart = -cam->lineheight / 2 + HEIGHT / 2;
	if (cam->wallstart < 0)
		cam->wallstart = 0;
	cam->wallend = cam->lineheight / 2 + HEIGHT / 2;
	if (cam->wallend >= HEIGHT)
		cam->wallend = HEIGHT - 1;
}

void	draw_camera(t_info *info, t_camera *cam, int x)
{
	set_wallpos(cam);
	sel_texture(cam);
	draw_texture(info, cam, x);
}
