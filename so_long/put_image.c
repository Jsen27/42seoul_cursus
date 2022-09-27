/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 14:49:57 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_var *var)
{
	var->glass = mlx_xpm_file_to_image(var->mlx, "./images/galss.xpm", var->x, var->y);
	var->rock = mlx_xpm_file_to_image(var->mlx, "./images/rock.xpm", var->x, var->y);
	var->exit = mlx_xpm_file_to_image(var->mlx, "./images/exit.xpm", var->x, var->y);
	var->apple = mlx_xpm_file_to_image(var->apple, "./images/apple.xpm", var->x, var->y);
	var->player = mlx_xpm_file_to_image(var->mlx, "./images/player.xpm", var->x, var->y);	
}