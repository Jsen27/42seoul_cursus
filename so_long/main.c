/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:58 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/23 21:32:43 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "so_long.h"

int	main(void)
{
	t_var	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 800, 600, "so_long");


	return (0);
}