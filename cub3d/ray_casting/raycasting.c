/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:03:47 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/18 15:21:43 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

static void	floor_ceiling(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < 480)
	{
		j = 0;
		while (j < 640)
		{
			if (i < 240)
			{
				info->buf[i][j] = info->element.floor_color[0] << 16;
				info->buf[i][j] += info->element.floor_color[1] << 8;
				info->buf[i][j] += info->element.floor_color[2];
			}
			else
			{
				info->buf[i][j] = info->element.ceil_color[0] << 16;
				info->buf[i][j] += info->element.ceil_color[1] << 8;
				info->buf[i][j] += info->element.ceil_color[2];
			}
			j++;
		}
		i++;
	}
}

static void	cal_raycasting(t_info *info)
{
	int			x;
	t_camera	cam;

	x = 0;
	floor_ceiling(info);
	while (x < WIDTH)
	{
		set_camera(info, &cam, x);
		draw_camera(info, &cam, x);
		x++;
	}
}

int	main_loop(t_info *info)
{
	cal_raycasting(info);
	draw(info);
	return (0);
}
