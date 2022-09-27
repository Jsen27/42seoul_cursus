/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:14:40 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 14:43:30 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

#include "./mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
typedef struct s_param
{
	int x;
	int y;
}	t_param;

void param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int				key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)
		param->y++;
	else if (keycode == KEY_S)
		param->y--;
	else if (keycode == KEY_A)
		param->x--;
	else if (keycode == KEY_D)
		param->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", param->x, param->y);
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	t_param param;
	
	param_init(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	mlx_loop(mlx);
	return 0;
}





typedef struct my_data{
	void *mlx;
	void *win;
	int x;
	int y;
	void *rock;
	void *glass;
	void *coin;

} data;

int main()
{
	data var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 800, 600, "testfile");
	var.rock = mlx_xpm_file_to_image(var.mlx, "./images/rock.xpm", &var.x, &var.y);
	var.glass = mlx_xpm_file_to_image(var.mlx, "./images/glass.xpm", &var.x, &var.y);
	var.coin = mlx_xpm_file_to_image(var.mlx, "./images/coin.xpm", &var.x, &var.y);

	mlx_put_image_to_window(var.mlx, var.win, var.rock, 0, 0);
	mlx_put_image_to_window(var.mlx, var.win, var.glass, 64, 0);
	mlx_put_image_to_window(var.mlx, var.win, var.coin, 128, 0);
	mlx_loop(var.mlx);
	
	return 0;
}