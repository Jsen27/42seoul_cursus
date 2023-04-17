/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngwch <youngwch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:17:08 by youngwch          #+#    #+#             */
/*   Updated: 2022/11/14 15:50:21 by youngwch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	reculsive_putnbr(int n, int fd)
{
	long long	num;
	char		tmp_ch;

	num = n;
	if (num == 0)
		return ;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	reculsive_putnbr(num / 10, fd);
	tmp_ch = num % 10 + '0';
	write(fd, &tmp_ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	reculsive_putnbr(n, fd);
}
