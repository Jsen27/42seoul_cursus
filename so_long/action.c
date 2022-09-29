/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:56:12 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 14:49:25 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		end_game(int move)
{
	printf("Congratulations!\n");
	printf("Your Score : %dstep", move);
	exit(1);
}

static void 	move_check(t_var *var, int x, int y)
{
	static int	move;

	if (var->map[x][y] == '0')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->glass, var->my_point.x, var->my_point.y);
		mlx_put_image_to_window(var->mlx, var->win, var->player, x, y);
		var->my_point.x = x;
		var->my_point.y = y;
		printf("movement : %d\n", ++move);
	}
	else if (var->map[x][y] == 'C')
	{
		mlx_put_image_to_window(var->mlx, var->win, var->glass, var->my_point.x, var->my_point.y);
		mlx_put_image_to_window(var->mlx, var->win, var->glass, x, y);
		mlx_put_image_to_window(var->mlx, var->win, var->player, x, y);
		var->my_point.x = x;
		var->my_point.y = y;
		var->apple_check--;
		printf("movement : %d\n", ++move);
	}
	else if (var->map[x][y] == 'E')
	{
		if (var->apple_check == 0)
			end_game(++move);
	}
}

int	move_action(int keycode, t_var *var)
{
	if (keycode == KEY_D)
		move_check(var, var->my_point.x + 16, var->my_point.y);
	else if (keycode == KEY_A)
		move_check(var, var->my_point.x - 16, var->my_point.y);
	else if (keycode == KEY_S)
		move_check(var, var->my_point.x, var->my_point.y + 16);
	else if (keycode == KEY_W)
		move_check(var, var->my_point.x, var->my_point.y - 16);
	return (0);
}