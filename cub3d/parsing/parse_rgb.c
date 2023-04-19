/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:51:47 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/19 17:20:15 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_comma_count(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			count ++;
	}
	if (count != 2)
		my_error();
}

static void	check_valid_color(char *str)
{
	int	i;

	if (!str || !*str || ft_strlen(str) > 4)
		my_error();
	if (*str == '+' || *str == '-')
		str ++;
	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			my_error();
	}
}

void	parse_rgb(char *str, int *color_store)
{
	char	**p_str;
	int		i;

	check_comma_count(str);
	p_str = ft_split(str, ',');
	check_str_count(p_str, 3);
	free(str);
	i = -1;
	while (++i < 3)
	{
		check_valid_color(p_str[i]);
		color_store[i] = ft_atoi(p_str[i]);
		free(p_str[i]);
		if (color_store[i] < 0 || color_store[i] > 255)
			my_error();
	}
	free(p_str);
}
