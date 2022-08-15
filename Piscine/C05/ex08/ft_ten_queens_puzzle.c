/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:51:31 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/01 11:08:48 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_arr(int *arr)
{
	int	i;

	i = 0;
	while (i < 10)
		put_char(arr[i++] + '0');
	put_char('\n');
}

int	check(int x, int *arr)
{
	int	i;
	int	temp;

	i = 0;
	while (i < x)
	{
		temp = arr[i] - arr[x];
		if (temp < 0)
			temp *= -1;
		if (arr[i] == arr[x] || x - i == temp)
			return (0);
		i++;
	}
	return (1);
}

void	queen(int x, int *cnt, int *arr)
{
	int	i;

	i = 0;
	if (x == 10)
	{
		*cnt += 1;
		print_arr(arr);
		return ;
	}
	else
	{
		while (i < 10)
		{
			arr[x] = i;
			if (check(x, arr))
				queen(x + 1, cnt, arr);
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (i < 10)
		arr[i++] = 0;
	queen(0, &cnt, arr); 
	return (cnt);
}
