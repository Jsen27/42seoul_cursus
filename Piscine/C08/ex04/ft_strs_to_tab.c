/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:20:46 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/06 19:50:23 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	total_len(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	temp = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (temp == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		temp[i].size = total_len(av[i]);
		temp[i].str = (char *) malloc(sizeof(char) * total_len(av[i]) + 1);
		if (temp[i].str == 0)
			return (0);
		temp[i].copy = (char *) malloc(sizeof(char) * total_len(av[i]) + 1);
		if (temp[i].copy == 0)
			return (0);
		ft_strcpy(temp[i].str, av[i]);
		ft_strcpy(temp[i].copy, av[i]);
		i++;
	}
	temp[i].size = 0;
	temp[i].str = 0;
	temp[i].copy = 0;
	return (temp);
}
