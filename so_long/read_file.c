/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/05 22:20:21 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_check(t_var *var, size_t len, size_t height)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < len)
		{
			if (var->map[i][j] == 'E')
				var->exit_check++;
			else if (var->map[i][j] == 'C')
				var->mushroom_check++;
			else if (var->map[i][j] == 'P')
			{
				var->player_check++;
				var->my_point.x = j;
				var->my_point.y = i;
			}
			else if (var->map[i][j] != '0' && var->map[i][j] != '1')
				print_error(4, var);
			j++;
		}
		i++;
	}
}

static void	test(t_var *var, size_t len, int line, int height)
{
	size_t	i;

	i = 0;
	if (line == height - 1 && len != ft_strlen(var->map[line]))
		print_error(4, var);
	else if (line < height - 1 && len != ft_strlen(var->map[line]) - 1)
		print_error(4, var);
	if (line == 0 || line == height - 1)
	{
		while (var->map[line][i] && i < len)
			if (var->map[line][i++] != '1')
				print_error(4, var);
	}
	else if (var->map[line][0] != '1' || var->map[line][len - 1] != '1')
		print_error(4, var);
}

size_t	get_height(char *file)
{
	int		fd;
	int		len;
	char	*str;

	len = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		len++;
		str = get_next_line(fd);
	}
	free(str);
	return (len);
}

size_t	read_file(char *file, t_var *var, size_t height)
{
	int		fd;
	size_t	line;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(3, var);
	var->map = ft_calloc(height, sizeof(char *));
	if (!var->map)
		print_error(2, var);
	line = 0;
	while (line < height)
		var->map[line++] = get_next_line(fd);
	len = ft_strlen(var->map[0]) - 1;
	line = 0;
	while (line < height)
		test(var, len, line++, height);
	fd = close(fd);
	map_check(var, len, height);
	if (var->mushroom_check <= 0 || var->exit_check != 1
		|| var->player_check != 1)
		print_error(4, var);
	return (len);
}
