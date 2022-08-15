/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:12:54 by sehjung           #+#    #+#             */
/*   Updated: 2022/05/22 12:55:55 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	a;

	a = 'z';
	while (a != 'a' - 1)
	{
		write (1, &a, 1);
		a--;
	}
}
