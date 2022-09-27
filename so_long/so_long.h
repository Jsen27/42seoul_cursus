/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:07:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 15:31:45 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"

typedef struct s_var
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
}				t_var;

size_t	read_file(char *file, t_var *var);
void	put_image(t_var *var, size_t len);