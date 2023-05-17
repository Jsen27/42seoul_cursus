/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:56:41 by youngwch          #+#    #+#             */
/*   Updated: 2023/05/17 21:06:22 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_dir(t_element *e, char **p_element, int *flag)
{
	if (!ft_strncmp(p_element[0], "EA", 2)
		&& ft_strlen(p_element[0]) == 2 && !flag[0])
	{
		flag[0] = 1;
		e->east_path = p_element[1];
		return (1);
	}
	else if (!ft_strncmp(p_element[0], "WE", 2)
		&& ft_strlen(p_element[0]) == 2 && !flag[1])
	{
		flag[1] = 1;
		e->west_path = p_element[1];
		return (1);
	}
	return (0);
}

static int	check_dir2(t_element *e, char **p_element, int *flag)
{
	if (!ft_strncmp(p_element[0], "SO", 2)
		&& ft_strlen(p_element[0]) == 2 && !flag[2])
	{
		flag[2] = 1;
		e->south_path = p_element[1];
		return (1);
	}
	else if (!ft_strncmp(p_element[0], "NO", 2)
		&& ft_strlen(p_element[0]) == 2 && !flag[3])
	{
		flag[3] = 1;
		e->north_path = p_element[1];
		return (1);
	}
	return (0);
}

static int	check_color(t_element *e, char **p_element, int *flag)
{
	if (!ft_strncmp(p_element[0], "F", 1)
		&& ft_strlen(p_element[0]) == 1 && !flag[4])
	{
		flag[4] = 1;
		parse_rgb(p_element[1], e->ceil_color);
		return (1);
	}
	else if (!ft_strncmp(p_element[0], "C", 1)
		&& ft_strlen(p_element[0]) == 1 && !flag[5])
	{
		flag[5] = 1;
		parse_rgb(p_element[1], e->floor_color);
		return (1);
	}
	return (0);
}

void	get_texture_path(t_element *e, char *str, int *flag)
{
	char	**p_element;

	if (!str)
		my_error();
	p_element = ft_split(str, ' ');
	check_str_count(p_element, 2);
	if (check_dir(e, p_element, flag) || check_dir2(e, p_element, flag))
	{
	}
	else if (check_color(e, p_element, flag))
	{
	}
	else
		my_error();
	free(p_element[0]);
	free(p_element);
	free(str);
}
