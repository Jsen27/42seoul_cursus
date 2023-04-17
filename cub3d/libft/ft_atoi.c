/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:58:06 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/16 10:36:50 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long long	reculsive_atoi(const char *str, int digit,
	int place_value, int sign)
{
	long long	ret_ll;

	if (digit == 0)
		return (0);
	ret_ll = reculsive_atoi(str, digit - 1, place_value * 10, sign)
		+ ((*(str + digit - 1) - '0') * place_value);
	return (ret_ll);
}

static int	find_digit(const char *str)
{
	int	index;

	index = 0;
	while (*(str + index) >= '0' && *(str + index) <= '9')
		index ++;
	return (index);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			digit;
	long long	result;

	sign = 1;
	while ((*(str) >= 9 && *(str) <= 13) || *(str) == ' ')
		str ++;
	if (*(str) == '-' || *(str) == '+')
	{
		if (*(str) == '-')
			sign = -1;
		str ++;
	}
	digit = find_digit(str);
	result = reculsive_atoi(str, digit, 1, sign);
	return (sign * result);
}
