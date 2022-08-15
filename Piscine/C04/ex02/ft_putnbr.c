/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:28:22 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/30 17:13:38 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print(char c)
{
	write (1, &c, 1);
	return ;
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_print('-');
		ft_print('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_print('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr (nb / 10);
	ft_print (nb % 10 + '0');
}
