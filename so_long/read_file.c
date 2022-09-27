/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 14:42:00 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_var *var)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (var->map[i++])
	{
		j = 0;
		while (var->map[i][j])
		{
			if(var->map[i][j] == 'E')
				var->exit_check++;
			else if (var->map[i][j] == 'C')
				var->apple_check++;
			else if (var->map[i][j] == 'P')
				var->player_check++;
			else if (var->map[i][j] != 0 && var->map[i][j] != 1)
			{
				printf("Map ERROR!\n");
				exit(-1);
			}
			j++;
		}
	}
	if (var->apple_check <= 0 || var->exit_check != 1 || var->player_check != 1)
	{
		printf("Map ERROR!\n");
		exit(-1);
	}
}

int	str_check(t_var *var, char *str, size_t len, int line)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str) - 1 != len)
		return (0);
	if (line == 0 || line == 4)
		while(str[i] && i < len)
			if (str[i++] != '1')
				return (0);
	else 
		if (str[0] != '1' || str[len - 1] != '1')
			return (0);
	var->map[line] = str;
	map_init(var, str);
}

size_t	read_file(char *file, t_var *var)
{
	int		fd;
	int		line;
	char	*str;
	size_t	len;

	fd = open(file, O_RDONLY);
	if (file == 0)
	{
		printf("File Open ERROR !\n");
		exit(-1);
	}
	str = get_next_line(fd);
	len = ft_strlen(str) - 1;
	line = 0;
	while (1)
	{
		str_check(var, str, len, line);
		str = get_next_line(fd);
		line++;
	}
	map_check(var);
	return (len);
}