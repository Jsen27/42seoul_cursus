/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:52:40 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/18 11:40:00 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	cub_check(char *map_path)
{
	if (!map_path)
		my_error();
	if (ft_strlen(map_path) < 4)
		my_error();
	if (ft_strncmp(".cub", map_path + ft_strlen(map_path) - 4, 4))
		my_error();
}

static void	set_pos(t_info *info)
{
	int	i;
	int	j;

	j = -1;
	while (info->map.map[++j])
	{
		i = -1;
		while (info->map.map[j][++i])
		{
			if (info->map.map[j][i] == 'E' || info->map.map[j][i] == 'W'
				|| info->map.map[j][i] == 'S' || info->map.map[j][i] == 'N')
			{
				info->pos_x = j + 0.5;
				info->pos_y = i + 0.5;
				info->map.start_direction = info->map.map[j][i];
			}
		}
	}
}

void	get_file(char *map_path, t_info *info)
{
	int	fd;

	cub_check(map_path);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		my_error();
	get_element(fd, info);
	get_map(fd, info);
	close(fd);
	set_pos(info);
}
