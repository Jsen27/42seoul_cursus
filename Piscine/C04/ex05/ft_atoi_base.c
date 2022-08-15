/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:37:10 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/30 17:13:18 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	checkblank(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v')
			continue ;
		else if (str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			continue ;
		break ;
	}
	if (i == 1)
		i--;
	return (i);
}

int	checkbase(char *str, char *base, int i, int digit)
{
	int	j;
	int	ans;

	j = 0;
	ans = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				ans = (ans * digit) + j;
				break ;
			}
			j++;
			if (base[j] == '\0')
				return (0);
		}
		i++;
	}
	return (ans);
}

int	checkerror1(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	checkerror2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	pm;
	int	ans;

	j = 0;
	i = checkblank(str);
	pm = 1;
	ans = 0;
	while (base[j] != '\0')
		j++;
	if (!(checkerror1(base) && checkerror2(base)))
		return (0);
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm *= -1;
		i++;
	}
	ans = checkbase(str, base, i, j);
	return (ans * pm);
}
