/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:25:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/09/25 02:09:03 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "so_long.h"

void	map_check(t_var *var)
{
	if (var->axe_check == 0 || var->exit_check != 1 || var->player_check != 1)
	{
		printf("Map ERROR!\n");
		exit(-1);
	}
}

void	map_init(t_var *var, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == 'E')
			var->exit_check++;
		else if (str[i] == 'C')
			var->axe_check++;
		else if (str[i] == 'P')
			var->player_check++;
		else if (str[i] != 0 && str[i] != 1)
		{
			printf("Map ERROR!\n");
			exit(-1);
		}
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

int	read_file(char *file, t_var *var)
{
	int		file;
	int		line;
	char	*str;
	size_t	len;

	file = open(file, O_RDONLY);
	if (file == 0)
	{
		printf("File Open ERROR !\n");
		exit(-1);
	}
	str = get_next_line(file);
	len = ft_strlen(str) - 1;
	line = 0;
	while (1)
	{
		str_check(var, str, len, line);
		str = get_next_line(file);
		line++;
	}
	map_check(var);
}