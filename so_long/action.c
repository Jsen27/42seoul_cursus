/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:56:12 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 20:01:04 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_var(t_var *var)
{
	size_t	i;
	
	i = 0;
	mlx_destroy_image(var->mlx, var->glass);
	mlx_destroy_image(var->mlx, var->rock);
	mlx_destroy_image(var->mlx, var->player);
	mlx_destroy_image(var->mlx, var->apple);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_window(var->mlx, var->win);
	free(var->mlx);
	while (var->map[i])
		free(var->map[i++]);
	free(var->map);
	free(var);
}

static void	end_game(int move, t_var *var)
{
	printf("Congratulations!\n");
	printf("Your Score : %dstep", move);
	free_var(var);
	system("leaks a.out");
	exit(0);
}

static void	move_check(t_var *var, int x, int y, int xx, int yy)
{
	static int	move;

	if (var->map[y][x] == '0' || var->map[y][x] == 'P')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->glass, var->my_point.x * 16, var->my_point.y * 16);
		mlx_put_image_to_window(var->mlx, var->win, var->player, (var->my_point.x * 16) + (xx * 16), (var->my_point.y * 16) + (yy * 16));
		var->my_point.x += xx;
		var->my_point.y += yy;
		printf("movement : %d\n", ++move);
	}
	else if (var->map[y][x] == 'C')
	{
		var->map[y][x] = '0';
		mlx_put_image_to_window(var->mlx, var->win, var->glass, var->my_point.x * 16, var->my_point.y * 16);
		mlx_put_image_to_window(var->mlx, var->win, var->glass, (var->my_point.x * 16) + (xx * 16), (var->my_point.y * 16) + (yy * 16));
		mlx_put_image_to_window(var->mlx, var->win, var->player, (var->my_point.x * 16) + (xx * 16), (var->my_point.y * 16) + (yy * 16));
		var->my_point.x += xx;
		var->my_point.y += yy;
		var->apple_check--;
		printf("movement : %d\n", ++move);
	}
	else if (var->map[y][x] == 'E')
	{
		if (var->apple_check == 0)
			end_game(++move, var);
	}
}

int	move_action(int keycode, t_var *var)
{
	if (keycode == KEY_D)
		move_check(var, var->my_point.x + 1, var->my_point.y, 1, 0);
	else if (keycode == KEY_A)
		move_check(var, var->my_point.x - 1, var->my_point.y, -1, 0);
	else if (keycode == KEY_S)
		move_check(var, var->my_point.x, var->my_point.y + 1, 0, 1);
	else if (keycode == KEY_W)
		move_check(var, var->my_point.x, var->my_point.y - 1, 0, -1);
	else if (keycode == KEY_ESC)
		exit(1);
	return (0);
}