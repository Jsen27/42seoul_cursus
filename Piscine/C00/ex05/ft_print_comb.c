/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:47:02 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/22 12:59:22 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	put_char(char a, char b, char c)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, &c, 1);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
	else
	{
		return ;
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 0;
	while (a < 8)
	{
		b = a + 1;
		while (b < 9)
		{
			c = b + 1;
			while (c < 10)
			{
				put_char (a + '0', b + '0', c + '0');
				c++;
			}
			b++;
		}
	a++;
	}
}
