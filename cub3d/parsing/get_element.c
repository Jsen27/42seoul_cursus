/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:43:49 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/18 14:40:25 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	all_flag_check(int *flag)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!flag[i])
			return (0);
	}
	return (1);
}

void	get_element(int fd, t_info *info)
{
	char	*str;
	char	*tmp_str;
	int		flag[6];
	int		i;

	i = -1;
	while (++i < 6)
		flag[i] = 0;
	while (1)
	{
		if (all_flag_check(flag))
			break ;
		str = get_next_line(fd);
		if (!str || str[ft_strlen(str) - 1] != '\n')
			my_error();
		if (str[0] == '\n' && ft_strlen(str) == 1)
		{
			free(str);
			continue ;
		}
		tmp_str = str;
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		free(tmp_str);
		get_texture_path(&info->element, str, flag);
	}
}
