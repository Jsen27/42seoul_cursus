/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:07:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/06 14:38:20 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define KEY_ESC					53
# define DESTROY					17
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define X_EVENT_KEY_RELEASE		3

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*glass;
	void	*rock;
	void	*player;
	void	*mushroom;
	void	*exit;
	char	**map;
	int		mushroom_check;
	int		exit_check;
	int		player_check;
	int		x;
	int		y;
	t_point	my_point;
}				t_var;

size_t	get_height(char *file);
size_t	read_file(char *file, t_var *var, size_t height);
void	put_image(t_var *var, size_t len, size_t height);
void	print_error(int error_num, t_var *var);
void	free_var(t_var *var);
int		move_action(int keycode, t_var *var);

#endif