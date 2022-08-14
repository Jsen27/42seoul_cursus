/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:05:17 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/14 20:05:17 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar((ptr + '0'));
		else
			ft_putchar((ptr + 'a' - 10));
		(*len)++;
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	if (!ptr)
		len += write(1, "0", 1);
	else
		ft_putptr(ptr, &len);
	return (len);
}
