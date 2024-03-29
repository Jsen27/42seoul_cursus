/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:56:12 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/03 21:11:50 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	end_game(int move, t_var *var)
{
	printf("Congratulations!\n");
	printf("Your Score : %dstep", move);
	free_var(var);
	exit(0);
}

static void	just_move(t_var *var, int x, int y, int *move)
{
	int	xx;
	int	yy;

	xx = x - var->my_point.x;
	yy = y - var->my_point.y;
	mlx_put_image_to_window(var->mlx, var->win, var->glass,
		var->my_point.x * 64, var->my_point.y * 64);
	mlx_put_image_to_window(var->mlx, var->win, var->player,
		(var->my_point.x * 64) + (xx * 64), (var->my_point.y * 64) + (yy * 64));
	var->my_point.x += xx;
	var->my_point.y += yy;
	*move += 1;
	printf("movement : %d\n", *move);
}

static void	apple_move(t_var *var, int x, int y, int *move)
{
	int	xx;
	int	yy;

	xx = x - var->my_point.x;
	yy = y - var->my_point.y;
	var->map[y][x] = '0';
	mlx_put_image_to_window(var->mlx, var->win, var->glass,
		var->my_point.x * 64, var->my_point.y * 64);
	mlx_put_image_to_window(var->mlx, var->win, var->glass,
		(var->my_point.x * 64) + (xx * 64), (var->my_point.y * 64) + (yy * 64));
	mlx_put_image_to_window(var->mlx, var->win, var->player,
		(var->my_point.x * 64) + (xx * 64), (var->my_point.y * 64) + (yy * 64));
	var->my_point.x += xx;
	var->my_point.y += yy;
	var->mushroom_check--;
	*move += 1;
	printf("movement : %d\n", *move);
}

static void	move_check(t_var *var, int x, int y)
{
	static int	move;

	if (var->map[y][x] == '0' || var->map[y][x] == 'P')
		just_move(var, x, y, &move);
	else if (var->map[y][x] == 'C')
		apple_move(var, x, y, &move);
	else if (var->map[y][x] == 'E')
		if (var->mushroom_check == 0)
			end_game(++move, var);
}

int	move_action(int keycode, t_var *var)
{
	if (keycode == KEY_D)
		move_check(var, var->my_point.x + 1, var->my_point.y);
	else if (keycode == KEY_A)
		move_check(var, var->my_point.x - 1, var->my_point.y);
	else if (keycode == KEY_S)
		move_check(var, var->my_point.x, var->my_point.y + 1);
	else if (keycode == KEY_W)
		move_check(var, var->my_point.x, var->my_point.y - 1);
	else if (keycode == KEY_ESC)
		free_var(var);
	return (0);
}
