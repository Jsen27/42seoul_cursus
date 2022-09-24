/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:07:21 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/23 21:36:29 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*glass;
	void	*coin;
	char	**map;
	int		coin;
	int		exit;
	int		player;
}				t_var;

// typedef struct s_map
// {
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	char	*line4;
// 	char	*line5;
// }				t_map;
