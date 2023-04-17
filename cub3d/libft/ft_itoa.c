/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:22:20 by youngwch          #+#    #+#             */
/*   Updated: 2022/12/20 11:17:42 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digit ++;
		n = n / 10;
	}
	return (digit);
}

static void	reculsive_assign(char *ptr, int digit, int n)
{
	long long	num;

	num = n;
	if (num < 0 && num > -10)
	{
		*(ptr + digit - 1) = num * -1 + '0';
		*ptr = '-';
		return ;
	}
	if (digit == 0)
		return ;
	*(ptr + digit - 1)
		= ((num >= 0) * num % 10 + (num < 0) * num % 10 * -1) + '0';
	reculsive_assign(ptr, digit - 1, num / 10);
	return ;
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*retptr;

	digit = count_digit(n);
	if (n < 0)
		digit ++;
	retptr = (char *)malloc(sizeof(char) * (digit + 1));
	if (retptr == 0)
		return (0);
	*(retptr + digit) = '\0';
	if (n == 0)
	{
		*retptr = '0';
		return (retptr);
	}
	reculsive_assign(retptr, digit, n);
	return (retptr);
}
