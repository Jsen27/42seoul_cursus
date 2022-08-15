/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:26:51 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/30 17:13:54 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	checkerror1(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	checkerror2(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		j++;
		}
		i++;
	}
	return (1);
}

void	ft_putbase(long long int nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putbase (-nbr, base);
		return ;
	}
	while (base[i] != '\0')
		i++;
	if (nbr >= i)
		ft_putbase((nbr / i), base);
	write(1, &base[nbr % i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (checkerror1(base) && checkerror2(base))
		ft_putbase(nbr, base);
}
