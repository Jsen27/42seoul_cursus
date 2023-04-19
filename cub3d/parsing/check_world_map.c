/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_world_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:03:18 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/18 10:59:40 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	surround_y_travel(char **map, int y, int x)
{
	int	i;

	i = x;
	while (i >= 0)
	{
		if (map[y][i] == '1')
			break ;
		if (map[y][i] == ' ' || i == 0)
			my_error();
		i --;
	}
	i = x;
	while (map[y][i])
	{
		if (map[y][i] == '1')
			break ;
		if (map[y][i] == ' ' || !map[y][i + 1])
			my_error();
		i ++;
	}
}

static void	surround_x_travel(char **map, int y, int x)
{
	int	i;

	i = y;
	while (i >= 0)
	{
		if (map[i][x] == '1')
			break ;
		if (map[i][x] == ' ' || i == 0 || (int)ft_strlen(map[i - 1]) <= i)
			my_error();
		i --;
	}
	i = y;
	while (map[i])
	{
		if (map[i][x] == '1')
			break ;
		if (map[i][x] == ' ' || !map[i + 1] || (int)ft_strlen(map[i + 1]) <= i)
			my_error();
		i ++;
	}
}

static void	surrounded_check(char **map)
{
	int	j;
	int	i;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == 'E' || map[j][i] == 'W'
				|| map[j][i] == 'S' || map[j][i] == 'N' || map[j][i] == '0')
			{
				surround_x_travel(map, j, i);
				surround_y_travel(map, j, i);
			}
		}
	}
}

void	character_check(char **map)
{
	int	i;
	int	j;
	int	ch_flag;

	ch_flag = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ')
				continue ;
			else if (map[i][j] == 'E' || map[i][j] == 'W'
				|| map[i][j] == 'S' || map[i][j] == 'N')
				ch_flag ++;
			else
				my_error();
		}
	}
	if (ch_flag != 1)
		my_error();
}

void	check_world_map(char **map)
{
	character_check(map);
	surrounded_check(map);
}
