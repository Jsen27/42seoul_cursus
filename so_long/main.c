/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:58 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 15:18:37 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	*var;
	size_t	len;
	
	var = malloc(sizeof(t_var));
	if (var == 0)
		return (-1);
	len = read_file(argv[1], var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, len * 16, 16 * 5, "so_long");
	put_image(var, len);
	mlx_loop(var->mlx);

	return (0);
}