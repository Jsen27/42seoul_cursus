/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/27 16:50:55 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check(t_var *var, size_t len)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	str = var->map;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && j < len)
		{
			if(str[i][j] == 'E')
				var->exit_check++;
			else if (str[i][j] == 'C')
				var->apple_check++;
			else if (str[i][j] == 'P')
				var->player_check++;
			else if (str[i][j] != 0 && str[i][j] != 1)
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
	{
		while(str[i] && i < len)
			if (str[i++] != '1')
				return (0);
	}
	else if (str[0] != '1' || str[len - 1] != '1')
		return (0);
	//var->map[line] = malloc (sizeof(char) * len + 1);
	ft_strlcpy(var->map[line], str, len);
	return (1);
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
	var->map = malloc(sizeof(char) * 5);
	str = get_next_line(fd);
	len = ft_strlen(str) - 1;
	line = 0;
	while (1)
	{
		str_check(var, str, len, line);
		str = get_next_line(fd);
		line++;
	}
	map_check(var, len);
	return (len);
}