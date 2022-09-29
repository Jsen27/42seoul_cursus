/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:56:12 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 16:04:52 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		end_game(int move)
{
	printf("Congratulations!\n");
	printf("Your Score : %dstep", move);
	exit(1);
}

static void 	move_check(t_var *var, int x, int y, int xx, int yy)
{
	static int	move;

	if (var->map[x][y] == '0' || var->map[x][y] == 'P')
	{
		printf("이동 전 x : %d  y : %d\n", var->my_point.x, var->my_point.y);
		mlx_put_image_to_window(var->mlx, var->win, var->glass, var->my_point.x * 16, var->my_point.y * 16);
		mlx_put_image_to_window(var->mlx, var->win, var->player, (var->my_point.x * 16) + (xx * 16), (var->my_point.y * 16) + (yy * 16));
		var->my_point.x += xx;
		var->my_point.y += yy;
		printf("이동 후 x : %d  y : %d\n", var->my_point.x, var->my_point.y);

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
	else
		return ;
}

int	move_action(int keycode, t_var *var)
{
	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
			printf("%c", var->map[i][j]);
		printf("\n");
	}*/
	if (keycode == KEY_D)
		move_check(var, var->my_point.x + 1, var->my_point.y, 1, 0);
	else if (keycode == KEY_A)
		move_check(var, var->my_point.x - 1, var->my_point.y, -1, 0);
	else if (keycode == KEY_S)
		move_check(var, var->my_point.x, var->my_point.y + 1, 0, 1);
	else if (keycode == KEY_W)
		move_check(var, var->my_point.x, var->my_point.y - 1, 0, -1);
	return (0);
}