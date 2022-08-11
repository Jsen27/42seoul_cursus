/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:33:28 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/08 18:33:28 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen(unsigned int num)
{
	int cnt;

	cnt = 0;
	while (num)
	{
		num /= 16;
		cnt++;
	}
	return (cnt);
}

static void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			else if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_printf_hex(unsigned int num, const char format)
{
	if ( num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hexlen(num));
}
