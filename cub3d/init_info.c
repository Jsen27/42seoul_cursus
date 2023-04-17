/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:26:36 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/17 21:41:06 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//벽에 충돌했을떄 벽 뚫려 보이는 문제
//처음 시작할때도 마찬가지

static void	init_buf(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->buf[y][x] = 0;
			x++;
		}
		y++;
	}
}

static void	direction_we(char direction, t_info *info)
{
	if (direction == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
	}
	else if (direction == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
	}
}

static void	direction_ns(char direction, t_info *info)
{
	if (direction == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	else if (direction == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
}

void	init_info(char direction, t_info *info)
{
	info->mlx = mlx_init();
	info->movespeed = 0.15;
	info->rotspeed = 0.1;
	if (direction == 'N' || direction == 'S')
		direction_ns(direction, info);
	else if (direction == 'W' || direction == 'E')
		direction_we(direction, info);
	init_buf(info);
	load_texture(info);
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "mlx");
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp,
			&info->img.size_l, &info->img.endian);
}
