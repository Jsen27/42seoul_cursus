/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/29 17:42:55 by sehjung          ###   ########seoul.kr  */
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
			if(var->map[i][j] == 'E')
				var->exit_check++;
			else if (var->map[i][j] == 'C')
				var->apple_check++;
			else if (var->map[i][j] == 'P')
			{
				var->player_check++;
				var->my_point.x = j;
				var->my_point.y = i;
			}
			else if (var->map[i][j] != '0' && var->map[i][j] != '1')
				print_error(3);
			j++;
		}
		i++;
	}
}

static void	str_check(t_var *var, char *str, size_t len, int line)
{
	size_t	i;

	i = 0;
	if (line == 4 && len != ft_strlen(str))
		print_error(3);
	if (line != 4 && len != ft_strlen(str) - 1)
		print_error(3);
	if (line == 0 || line == 4)
	{
		while(str[i] && i < len)
			if (str[i++] != '1')
				print_error(3);
	}
	else if (str[0] != '1' || str[len - 1] != '1')
		print_error(3);
	var->map[line] = malloc(sizeof(char) * len);
	if (!var->map[line])
		print_error(1);
	ft_strlcpy(var->map[line], str, len + 1);
	free(str);
}

size_t	read_file(char *file, t_var *var)
{
	int		fd;
	size_t	line;
	char	*str;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error(2);
	var->map = malloc(sizeof(char *) * 5);
	if (!var->map)
		print_error(1);
	str = get_next_line(fd);
	len = ft_strlen(str) - 1;
	line = 0;
	while (line < 5)
	{
		str_check(var, str, len, line);
		str = get_next_line(fd);
		line++;
	}
	fd = close(fd);
	map_check(var, len);
	if (var->apple_check <= 0 || var->exit_check != 1 || var->player_check != 1)
		print_error(3);
	return (len);
}