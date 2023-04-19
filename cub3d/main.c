/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:02:39 by sehjung           #+#    #+#             */
/*   Updated: 2023/04/18 14:55:51 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		my_error();
	get_file(argv[1], &info);
	init_info(info.map.start_direction, &info);
	mlx_loop_hook(info.mlx, main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, 17, 0, redcross, NULL);
	mlx_loop(info.mlx);
	exit(0);
}
