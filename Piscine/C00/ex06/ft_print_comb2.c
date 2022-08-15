/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:22:18 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/22 13:13:30 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print(char c)
{
	write (1, &c, 1);
}

void	ft_first(int first)
{
	if (first < 10)
	{
		ft_print('0');
		ft_print(first + '0');
	}
	else
	{
		ft_print((first / 10) + '0');
		ft_print((first % 10) + '0');
	}
	ft_print(' ');
}

void	ft_second(int second, int first)
{
	if (second < 10)
	{
		ft_print('0');
		ft_print(second + '0');
	}
	else
	{
		ft_print((second / 10) + '0');
		ft_print((second % 10) + '0');
	}
	if ((first == 98) && (second == 99))
	{
		return ;
	}
	ft_print(',');
	ft_print(' ');
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;
	int	cnt;

	first = 0;
	second = 1;
	cnt = 1;
	while (first < 99)
	{
		ft_first(first);
		ft_second(second, first);
		second++;
		if (second == 100)
		{
			cnt++;
			second = cnt;
			first++;
		}
	}
}
