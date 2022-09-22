/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:58:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/22 20:36:24 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return 0;
}

int main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hook test");

	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_loop(vars.mlx);

	return 0;
}