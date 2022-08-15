/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:17:26 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/08 23:33:26 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long int	num;

	num = nb;
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		ft_putnbr (num / 10);
	ft_putchar (num % 10 + '0');
}

void	doop(int a, int b, int sel, int (**f)(int, int))
{
	int	ans;

	if (sel == 0)
		ans = f[0](a, b);
	else if (sel == 1)
		ans = f[1](a, b);
	else if (sel == 2)
		ans = f[2](a, b);
	else if (sel == 3 && b != 0)
		ans = f[3](a, b);
	else if (sel == 4)
		ans = f[4](a, b);
	else if (sel == 5 && b != 0)
		ans = f[5](a, b);
	if (sel == 3 && b == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	else if (sel == 5 && b == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	ft_putnbr (ans);
}

int	blank(int a, int b)
{
	a += 0;
	b += 0;
	return (0);
}

int	check_sel(char *str)
{
	if (str[0] == '\0' || str[1] != '\0')
		return (0);
	if (str[0] == '+')
		return (1);
	else if (str[0] == '-')
		return (2);
	else if (str[0] == '/')
		return (3);
	else if (str[0] == '*')
		return (4);
	else if (str[0] == '%')
		return (5);
	else
		return (0);
}
