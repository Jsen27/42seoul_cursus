/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:58 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 22:21:23 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int error_num)
{
	printf("Error\n");
	if (error_num == 0)
		printf("Usage : ./so_long (map).ber\n");
	else if (error_num == 1)
		printf("malloc error !\n");
	else if (error_num == 2)
		printf("file open error !\n");
	else if (error_num == 3)
		printf("map error !\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_var	*var;
	size_t	len;
	
	if (argc != 2)
		print_error(0);
	var = malloc(sizeof(t_var));
	if (!var)
		print_error(1);
	var->apple_check = 0;
	var->exit_check = 0;
	var->player_check = 0;
	len = read_file(argv[1], var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, len * 16, 16 * 5, "so_long");
	put_image(var, len);
	mlx_hook(var->win, X_EVENT_KEY_RELEASE, 0, &action, 0);
	mlx_loop(var->mlx);

	return (0);
}