/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:07:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 14:49:24 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define X_EVENT_KEY_RELEASE		3

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	void	*glass;
	void	*rock;
	void	*player;
	void	*apple;
	void	*exit;
	char	**map;
	int		apple_check;
	int		exit_check;
	int		player_check;
	int		x;
	int		y;
	t_point	my_point;
}				t_var;

size_t	read_file(char *file, t_var *var);
void	put_image(t_var *var, size_t len);
void	print_error(int error_num);
int		move_action(int keycode, t_var *var);
