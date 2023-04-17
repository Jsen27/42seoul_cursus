/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:57:03 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/17 22:09:47 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_ar(int key, t_info *info, double olddir_x, double oldplane_x)
{
	if (key == K_AR_R)
	{
		info->dir_x = info->dir_x * cos(-info->rotspeed)
			- info->dir_y * sin(-info->rotspeed);
		info->dir_y = olddir_x * sin(-info->rotspeed)
			+ info->dir_y * cos(-info->rotspeed);
		info->plane_x = info->plane_x * cos(-info->rotspeed)
			- info->plane_y * sin(-info->rotspeed);
		info->plane_y = oldplane_x * sin(-info->rotspeed)
			+ info->plane_y * cos(-info->rotspeed);
	}
	else if (key == K_AR_L)
	{
		info->dir_x = info->dir_x * cos(info->rotspeed)
			- info->dir_y * sin(info->rotspeed);
		info->dir_y = olddir_x * sin(info->rotspeed)
			+ info->dir_y * cos(info->rotspeed);
		info->plane_x = info->plane_x * cos(info->rotspeed)
			- info->plane_y * sin(info->rotspeed);
		info->plane_y = oldplane_x * sin(info->rotspeed)
			+ info->plane_y * cos(info->rotspeed);
	}
}

static void	key_ad(int key, t_info *info)
{
	if (key == K_A)
	{
		if (info->map.map[(int)(info->pos_x - info->plane_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->plane_x * info->movespeed;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->plane_y * info->movespeed)] != '1')
			info->pos_y -= info->plane_y * info->movespeed;
	}
	else if (key == K_D)
	{
		if (info->map.map[(int)(info->pos_x + info->plane_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->plane_x * info->movespeed;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->plane_y * info->movespeed)] != '1')
			info->pos_y += info->plane_y * info->movespeed;
	}
}

static void	key_ws(int key, t_info *info)
{
	if (key == K_W)
	{
		if (info->map.map[(int)(info->pos_x + info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_x * info->movespeed;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_y * info->movespeed)] != '1')
			info->pos_y += info->dir_y * info->movespeed;
	}
	else if (key == K_S)
	{
		if (info->map.map[(int)(info->pos_x - info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_x * info->movespeed;
		if (info->map.map[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_y * info->movespeed)] != '1')
			info->pos_y -= info->dir_y * info->movespeed;
	}
}

int	key_press(int key, t_info *info)
{
	if (key == K_W || key == K_S)
		key_ws(key, info);
	else if (key == K_A || key == K_D)
		key_ad(key, info);
	else if (key == K_AR_L || key == K_AR_R)
		key_ar(key, info, info->dir_x, info->plane_x);
	else if (key == K_ESC)
		exit(0);
	return (0);
}

int	redcross(int key_code, void *data)
{
	(void)key_code;
	data = NULL;
	exit(0);
}
