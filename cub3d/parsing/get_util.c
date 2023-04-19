/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:02:20 by youngwch          #+#    #+#             */
/*   Updated: 2023/04/18 11:02:20 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_str_count(char **p_str, int count)
{
	int	i;

	i = 0;
	while (p_str[i])
		i++;
	if (i != count)
		my_error();
}

void	my_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
