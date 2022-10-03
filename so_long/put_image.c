/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/03 20:09:25 by sehjung          ###   ########.fr       */
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
			if (var->map[i][j] == '1')
				mlx_put_image_to_window(var->mlx,
					var->win, var->rock, j * 64, i * 64);
			else if (var->map[i][j] == 'P')
				mlx_put_image_to_window(var->mlx,
					var->win, var->player, j * 64, i * 64);
			else if (var->map[i][j] == 'E')
				mlx_put_image_to_window(var->mlx,
					var->win, var->exit, j * 64, i * 64);
			else if (var->map[i][j] == 'C')
				mlx_put_image_to_window(var->mlx,
					var->win, var->mushroom, j * 64, i * 64);
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
	var->glass = mlx_xpm_file_to_image(var->mlx,
			"./images/glass.xpm", &var->x, &var->y);
	var->rock = mlx_xpm_file_to_image(var->mlx,
			"./images/rock.xpm", &var->x, &var->y);
	var->exit = mlx_xpm_file_to_image(var->mlx,
			"./images/exit.xpm", &var->x, &var->y);
	var->mushroom = mlx_xpm_file_to_image(var->mlx,
			"./images/apple.xpm", &var->x, &var->y);
	var->player = mlx_xpm_file_to_image(var->mlx,
			"./images/player.xpm", &var->x, &var->y);
	while (i < 5)
	{
		j = -1;
		while (++j < len)
			mlx_put_image_to_window(var->mlx,
				var->win, var->glass, j * 64, i * 64);
		i++;
	}
	make_map(var, len);
}
