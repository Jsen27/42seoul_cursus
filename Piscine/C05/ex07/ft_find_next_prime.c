/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:11:06 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/01 21:47:18 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	i = 2;
	while (i < nb / i)
	{
		if (nb % i == 0)
		{
			nb++;
			i = 1;
		}
		i++;
	}
	return (nb);
}

#include<stdio.h>
int main()
{
	printf("%d",ft_find_next_prime(2147483647));

	return 0;
}