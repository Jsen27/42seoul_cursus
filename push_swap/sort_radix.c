/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:40:33 by sehjung           #+#    #+#             */
/*   Updated: 2022/11/09 21:59:11 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(int *stack_a, int *stack_b, int numbers)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (check_sort(stack_a))
	{
		j = 0;
		while (j < numbers)
		{
			temp = stack_a[0];
			if ((temp >> i) & 1)
				ft_rotate(stack_a, 'a');
			else
				ft_push(stack_a, stack_b, 'b');
			j++;
		}
		while (stack_b[0])
			ft_push(stack_b, stack_a, 'a');
		i++;
	}
}
