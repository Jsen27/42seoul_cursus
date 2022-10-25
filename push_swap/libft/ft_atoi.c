/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:47:27 by sehjung           #+#    #+#             */
/*   Updated: 2022/10/21 16:47:16 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

static void	checkdiff(char *str)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			cnt++;
			continue;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue;
		}
		print_error(1);
	}
}

static size_t	checkblank(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
		{
			i++;
			continue ;
		}
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	checkdiff(&str[i]);
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		pm;
	long	ans;

	i = checkblank((char *)str);
	pm = 1;
	ans = 0;
	if (str[i] == '-')
		pm *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = (ans * 10) + (str[i] - '0');
		if (ans > 2147483647 && pm == 1)
			print_error(1);
		if (ans > 2147483648 && pm == -1)
			print_error(1);
		i++;
	}
	if (str[i] != '\0')
		print_error(1);
	return (ans * pm);
}
