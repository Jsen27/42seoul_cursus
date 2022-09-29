/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 20:34:42 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_map(t_var *var, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < len)
		{
			if(var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx, var->win, var->rock, j * 16, i * 16);
			else if (var->map[i][j] == 'P')
				mlx_put_image_to_window(var->mlx, var->win, var->player, j * 16, i * 16);
			else if (var->map[i][j] == 'E')
				mlx_put_image_to_window(var->mlx, var->win, var->exit, j * 16, i * 16);
			else if (var->map[i][j] == 'C')
				mlx_put_image_to_window(var->mlx, var->win, var->apple, j * 16, i * 16);
			j++;
		}
		i++;
	}
}

void	put_image(t_var *var, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	var->glass = mlx_xpm_file_to_image(var->mlx, "./images/glass.xpm", &var->x, &var->y);
	var->rock = mlx_xpm_file_to_image(var->mlx, "./images/rock.xpm", &var->x, &var->y);
	var->exit = mlx_xpm_file_to_image(var->mlx, "./images/exit.xpm", &var->x, &var->y);
	var->apple = mlx_xpm_file_to_image(var->mlx, "./images/apple.xpm", &var->x, &var->y);
	var->player = mlx_xpm_file_to_image(var->mlx, "./images/player.xpm", &var->x, &var->y);
	while (i < 5)
	{
		j = 0;
		while (j < len)
		{
			mlx_put_image_to_window(var->mlx, var->win, var->glass, j * 16, i * 16);
			j++;
		}
		i++;
	}
	make_map(var, len);
}