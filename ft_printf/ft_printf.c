/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:11:37 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/08 17:11:37 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_printf_ptr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printf_hex(va_arg(ap, unsigned int), c));
	else if (c == '%')
		return (ft_putpercent());
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	i;
	int		cnt;
	int		len;

	va_start(ap, input);
	i = 0;
	cnt = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			len = find_format(input[i], ap);
		}
		else
			len = ft_putchar(input[i]);
		if (len == -1)
			return (-1);
		cnt += len;
		i++;
	}
	va_end(ap);
	return (cnt);
}
