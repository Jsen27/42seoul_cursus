/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/05 19:16:26 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_check(t_var *var, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 5)
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

static void	str_check(t_var *var, char *str, size_t len, int line)
{
	size_t	i;
	int		error_flag;

	i = 0;
	error_flag = 0;
	if (line == 4 && len != ft_strlen(str))
		error_flag = 1;
	if (line != 4 && len != ft_strlen(str) - 1)
		error_flag = 1;
	if (line == 0 || line == 4)
	{
		while (str[i] && i < len)
			if (str[i++] != '1')
				error_flag = 1;
	}
	else if (str[0] != '1' || str[len - 1] != '1')
		error_flag = 1;
	var->map[line] = ft_calloc(len, sizeof(char));
	if (!var->map[line])
		print_error(5, var);
	ft_strlcpy(var->map[line], str, len + 1);
	free(str);
	if (error_flag == 1)
		print_error(4, var);
}

size_t	read_file(char *file, t_var *var)
{
	int		fd;
	size_t	line;
	size_t	len;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(3, var);
	var->map = ft_calloc(5, sizeof(char *));
	if (!var->map)
		print_error(2, var);
	str = get_next_line(fd);
	len = ft_strlen(str) - 1;
	line = 0;
	while (line < 5)
	{
		str_check(var, str, len, line++);
		str = get_next_line(fd);
	}
	fd = close(fd);
	map_check(var, len);
	if (var->mushroom_check <= 0 || var->exit_check != 1
		|| var->player_check != 1)
		print_error(4, var);
	return (len);
}
