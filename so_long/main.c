/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:58 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/06 15:49:11 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	g_height;

void	map_error(t_var *var)
{
	size_t	i;

	i = 0;
	while (i < g_height)
		free(var->map[i++]);
	free(var->map);
	free(var);
}

void	free_var(t_var *var)
{
	size_t	i;

	i = 0;
	mlx_destroy_image(var->mlx, var->glass);
	mlx_destroy_image(var->mlx, var->rock);
	mlx_destroy_image(var->mlx, var->player);
	mlx_destroy_image(var->mlx, var->mushroom);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_window(var->mlx, var->win);
	while (i < g_height)
		free(var->map[i++]);
	free(var->map);
	free(var);
	exit(0);
}

void	print_error(int error_num, t_var *var)
{
	printf("Error\n");
	if (error_num == 0)
		printf("Usage : ./so_long (mapfile).ber\n");
	else if (error_num == 1 || error_num == 2 || error_num == 5)
		printf("malloc error !\n");
	else if (error_num == 3)
		printf("file open error !\n");
	else if (error_num == 4)
		printf("map error !\n");
	if (error_num == 2 || error_num == 3)
		free(var);
	else if (error_num == 4 || error_num == 5)
		map_error(var);
	exit(-1);
}

int	destory_game(t_var *var)
{
	free_var(var);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	*var;
	size_t	len;

	if (argc != 2)
		print_error(0, NULL);
	var = malloc(sizeof(t_var));
	if (!var)
		print_error(1, var);
	g_height = get_height(argv[1]);
	var->mushroom_check = 0;
	var->exit_check = 0;
	var->player_check = 0;
	len = read_file(argv[1], var, g_height);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, len * 64, 64 * g_height, "so_long");
	put_image(var, len, g_height);
	mlx_hook(var->win, X_EVENT_KEY_RELEASE, 0, &move_action, var);
	mlx_hook(var->win, DESTROY, 0, &destory_game, var);
	mlx_loop(var->mlx);
	return (0);
}
