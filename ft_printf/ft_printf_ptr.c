/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 18:36:53 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/08 18:36:53 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_printf_ptr(ptr / 16);
		ft_printf_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar((ptr + '0'));
		else
			ft_putchar ((ptr - 10 +'a'));
		*len++;
	}
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int len;

	len = 0;
	len += write(1, "0x", 2);
	if (!ptr)
		len += write(1, "0", 1);
	else
		ft_putptr(ptr, &len);
	return (len);
}