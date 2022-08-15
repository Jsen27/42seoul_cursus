/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:57:48 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/22 13:10:16 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combn(int n, int digit, int bef, int*num)
{
	int	idx;
	int	cur;

	idx = 0;
	cur = bef + 1;
	if (digit == n)
	{
		while (idx < n)
			ft_putchar(num[idx++] + '0');
		if (num[0] != 10 - n)
			write(1, ", ", 2);
		return ;
	}
	while (cur <= 9)
	{
		num[digit] = cur;
		combn(n, digit + 1, cur, num);
		cur++;
	}
}

void	ft_print_combn(int n)
{
	int	num[10];

	combn(n, 0, -1, num);
}
