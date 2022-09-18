/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:05:48 by sehjung           #+#    #+#             */
/*   Updated: 2022/08/14 20:05:48 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}
